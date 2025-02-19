# MakeCode extension to run ML4F models

[![MakeCode Project](https://github.com/microbit-foundation/pxt-microbit-ml-runner/actions/workflows/makecode.yml/badge.svg)](https://github.com/microbit-foundation/pxt-microbit-ml-runner/actions/workflows/makecode.yml)
[![Header Generator Tests](https://github.com/microbit-foundation/pxt-microbit-ml-runner/actions/workflows/header-gen.yml/badge.svg)](https://github.com/microbit-foundation/pxt-microbit-ml-runner/actions/workflows/header-gen.yml)

This project wraps [ML4F](https://github.com/microsoft/ml4f) to invoke a known
type of model that requires some data pre-processing.
The wrapper is provided as a slim library to be able to be import it
into other MakeCode extensions and as a MicroPython module.


## How to use external ML4F model with this extension

The ML4F wrapper library can be found in the `mlrunner` folder.
This repository also includes a pre-compiled model (inclusion can be controlled
via compilation flags configured in the `pxt.json` file) and MakeCode files
to be able to build it and test it as a MakeCode project.

The files listed in the `pxt.json` as `testFiles` are only used when
this repository is compiled as a MakeCode project. When used as an extension
a similar implementation needs to be provided externally.


## Use as a MakeCode Extension

This repository can be added as an **extension** in MakeCode.

* Open [MakeCode beta](https://makecode.microbit.org/beta)
* Click on **New Project**
* Click on **Extensions** under the gearwheel menu
* Search for **https://github.com/microbit-foundation/pxt-microbit-ml-runner** and import


## Edit as a MakeCode project

### In MakeCode online editor

To edit this repository in MakeCode.

* Open [MakeCode](https://makecode.microbit.org)
* Click on **Import** then click on **Import URL**
* Paste **https://github.com/microbit-foundation/pxt-microbit-ml-runner** and click import

### Building locally

Ensure you have the required toolchain to build for V1 and V2
(arm-none-eabi-gcc, python, yotta, cmake, ninja, srec_cat) or docker.

```bash
git clone https://github.com/microbit-foundation/pxt-microbit-ml-runner
cd pxt-microbit-ml-runner
npm install pxt --no-save
npx pxt target microbit --no-save
npx pxt install
PXT_FORCE_LOCAL=1 npx pxt
```

For the V1 build Yotta can hit the GitHub rate limits quite easily if the
project is built from a clean state more than once.
A V2-only build can be triggered with the `PXT_COMPILE_SWITCHES=csv---mbcodal`
environmental variable.

```
PXT_FORCE_LOCAL=1 PXT_NODOCKER=1 PXT_COMPILE_SWITCHES=csv---mbcodal npx pxt
```

> [!CAUTION]
> **When updating this repository, do NOT push changes to the `enums.d.ts`
> or `shims.d.ts` files.**
>
> These are autogenerated by MakeCode to contain the enums and function shims
> from the C++ code to be accessible via TypeScript. However, these are only
> needed for the test code, and should **not** be shipped as it will affect
> its usage as a MakeCode extension.
> 
> It's recommended to run locally: `git update-index --skip-worktree <file>`
>
> Unfortunately, adding `enums.d.ts` and `shims.d.ts` to the `testFiles` entry
> in `pxt.json` does not work, and they need to be added to `files` (so they
> end up included with the extension) and so, they should be kept empty.
> Building the project locally compiles all the test files, will add code
> to these `.d.ts` files, which should not be pushed.


## Build flags

These flags can be added to a project including this extension, to modify
the default behaviour of the extension code.

### Built-in ML model

> [!NOTE]
> This flag is only applicable when building this repository as a MakeCode
> project. When used as a MakeCode extension, the files with the built-in
> model will not be included and the build will fail.

The `MLRUNNER_USE_EXAMPLE_MODEL` flag can be used to add into a project an
example model included in this extension.

- 0: This is the default behaviour, no built-in module is build at all by
  this extension.
- 1: Includes a ML-Trainer model converted with ML4F. Trained with 3 classes,
  shake, circle and still.
- 2: This will include the Keras ADL model converted with ML4F.
  This model is too large and might not fit in normal builds without excluding
  the BLE SoftDevice, so its usage is discouraged.
  Classes: Jumping, Running, Standing, Walking

```json
{
    "yotta": {
        "config": {
            "MLRUNNER_USE_EXAMPLE_MODEL": 1
        }
    }
}
```

This flag name is expanded to `DEVICE_MLRUNNER_USE_EXAMPLE_MODEL` in the
source code.

### Serial debug data

By default, the MakeCode project prints debug data via serial.
To disable this feature, set the `ML_DEBUG_PRINT` flag to `0`.

## Testing the model with known data

A special mode has been included to test the filters and model output.
This mode can be triggered by changing a define flag in the source code and
including a couple of test files with accelerometer samples, expected filter
and model results, and a model blob to test.

The results are printed to serial and nothing else runs on the device. So, it
is designed for one-off tests for validation and debugging.

To run the tests:
- Obtain the `autogenerate.ts` and `modeltest/testdata.h` files under test and
  replace the versions already present in this reporistory.
  - You can copy the files from within the `modeltest/testdatax/` folders
  - Or create new ones using the `ml4f-output` npm script within the
    [CreateAI](https://github.com/microbit-foundation/ml-trainer) project
- If you have a `main.ts` file using the model under test, add it as well
  - Otherwise you might need to manually update the `main.ts` file for the
    actions configured in the model under test
- Set the [`ML_TEST_MODEL` macro define](https://github.com/microbit-foundation/pxt-microbit-ml-runner/blob/a79fdaf51ebf221843a7be4c948f586643471991/testextension.cpp#L11)
  value to `1`
- Build the MakeCode project locally (`npx pxt`) and flash the micro:bit
- Connect a serial terminal and review the printed data


## License

This software is under the MIT open source license.

[SPDX-License-Identifier: MIT](LICENSE)


## Code of Conduct

Trust, partnership, simplicity and passion are our core values we live and
breathe in our daily work life and within our projects. Our open-source
projects are no exception. We have an active community which spans the globe
and we welcome and encourage participation and contributions to our projects
by everyone. We work to foster a positive, open, inclusive and supportive
environment and trust that our community respects the micro:bit code of
conduct. Please see our [code of conduct](https://microbit.org/safeguarding/)
which outlines our expectations for all those that participate in our
community and details on how to report any concerns and what would happen
should breaches occur.


#### Metadata (used for search)

* for PXT/microbit
