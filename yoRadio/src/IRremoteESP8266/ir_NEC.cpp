#define __STDC_LIMIT_MACROS
#include "ir_NEC.h"
#include <stdint.h>
#include <algorithm>
#include "IRrecv.h"
#include "IRsend.h"
#include "IRutils.h"

#if (SEND_NEC || SEND_SHERWOOD || SEND_AIWA_RC_T501 || SEND_SANYO || \
     SEND_MIDEA24)

void IRsend::sendNEC(uint64_t data, uint16_t nbits, uint16_t repeat) {
  sendGeneric(kNecHdrMark, kNecHdrSpace, kNecBitMark, kNecOneSpace, kNecBitMark,
              kNecZeroSpace, kNecBitMark, kNecMinGap, kNecMinCommandLength,
              data, nbits, 38, true, 0,
              33);

  if (repeat)
    sendGeneric(kNecHdrMark, kNecRptSpace, 0, 0, 0, 0,
                kNecBitMark, kNecMinGap, kNecMinCommandLength, 0,
                0,
                38, true, repeat - 1,
                33);
}

uint32_t IRsend::encodeNEC(uint16_t address, uint16_t command) {
  command &= 0xFF;
  command = reverseBits(command, 8);
  command = (command << 8) + (command ^ 0xFF);
  if (address > 0xFF) {
    address = reverseBits(address, 16);
    return ((address << 16) + command);
  } else {
    address = reverseBits(address, 8);
    return (address << 24) + ((address ^ 0xFF) << 16) + command;  // Normal.
  }
}
#endif

#if (DECODE_NEC || DECODE_SHERWOOD || DECODE_AIWA_RC_T501 || DECODE_SANYO)

bool IRrecv::decodeNEC(decode_results *results, uint16_t offset,
                       const uint16_t nbits, const bool strict) {
  if (results->rawlen < kNecRptLength + offset - 1)
    return false;
  if (strict && nbits != kNECBits)
    return false;

  uint64_t data = 0;

  if (!matchMark(results->rawbuf[offset++], kNecHdrMark)) return false;

  if (matchSpace(results->rawbuf[offset], kNecRptSpace) &&
      matchMark(results->rawbuf[offset + 1], kNecBitMark) &&
      (offset + 2 <= results->rawlen ||
       matchAtLeast(results->rawbuf[offset + 2], kNecMinGap))) {
    results->value = kRepeat;
    results->decode_type = NEC;
    results->bits = 0;
    results->address = 0;
    results->command = 0;
    results->repeat = true;
    return true;
  }

  if (!matchGeneric(results->rawbuf + offset, &data,
                    results->rawlen - offset, nbits,
                    0, kNecHdrSpace,
                    kNecBitMark, kNecOneSpace,
                    kNecBitMark, kNecZeroSpace,
                    kNecBitMark, kNecMinGap, true)) return false;

  uint8_t command = (data & 0xFF00) >> 8;

  if ((command ^ 0xFF) != (data & 0xFF)) {
    if (strict) return false;
    command = 0;
  }

  results->bits = nbits;
  results->value = data;
  results->decode_type = NEC;

  results->command = reverseBits(command, 8);

  uint8_t address = (data & 0xFF000000) >> 24;
  uint8_t address_inverted = (data & 0x00FF0000) >> 16;
  if (address == (address_inverted ^ 0xFF))

    results->address = reverseBits(address, 8);
  else
    results->address = reverseBits((data >> 16) & UINT16_MAX, 16);
  return true;
}
#endif
