#ifndef I18N_H_
#define I18N_H_
#include "IRremoteESP8266.h"
#ifndef _IR_LOCALE_
#define _IR_LOCALE_ uk-UA
#endif
#define ENQUOTE_(x) #x
#define ENQUOTE(x) ENQUOTE_(x)
#ifdef _IR_LOCALE_
#include ENQUOTE(locale/_IR_LOCALE_.h)
#endif
#include "locale/defaults.h"
#endif
