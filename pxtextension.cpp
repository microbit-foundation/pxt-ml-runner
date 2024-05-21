#include <pxt.h>

// Workaround to issue in pxt-microbit prepending to macro names
// https://github.com/microsoft/pxt-microbit/issues/5352
#ifdef DEVICE_MLRUNNER_INCLUDE_MODEL_EXAMPLE
#define MLRUNNER_INCLUDE_MODEL_EXAMPLE      MLRUNNER_INCLUDE_MODEL_EXAMPLE
#endif

// ML model is too large for V1, so avoid including it or compilation will fail
#if MICROBIT_CODAL
    #include "mlrunner.h"
#else
    // Create V1 shims to raise 927 panic code
    namespace mlrunner {
        //% blockId=mlrunner_input_length
        int ml_getInputLen() {
            return DEVICE_NOT_SUPPORTED;
        }
    }
#endif

namespace mlrunner {
    //% blockId=mlrunner_emit_ml_event
    void emit_ml_event() {
        // Different value used between simulator and hardware to check it works
        MicroBitEvent evt(71, 2);
    }
}
