# Proof of Concept for a MakeCode extension to run ML models

This project is left slim to be able to be imported in other MakeCode
extensions and a MicroPython module.

## Use as Extension

This repository can be added as an **extension** in MakeCode.

* open [MakeCode](https://makecode.microbit.org)
* click on **New Project**
* click on **Extensions** under the gearwheel menu
* search for **https://github.com/microbit-foundation/pxt-ml-runner-poc** and import

## Edit this project

### In MakeCode online editor

To edit this repository in MakeCode.

* open [MakeCode](https://makecode.microbit.org)
* click on **Import** then click on **Import URL**
* paste **https://github.com/microbit-foundation/pxt-ml-runner-poc** and click import


## Building locally

```bash
git clone https://github.com/microbit-foundation/pxt-ml-runner-poc
cd pxt-ml-runner-poc
npm install pxt --no-save
npx pxt target microbit --no-save
cp node_modules/pxtcli.json ./pxtcli.json
npm install pxt-microbit@6.1.10 --no-save
mv ./pxtcli.json node_modules/pxtcli.json
npx pxt install
PXT_FORCE_LOCAL=1 PXT_NODOCKER=1 PXT_COMPILE_SWITCHES=csv---mbcodal npx pxt
```

> ![WARNING]
> Forcing microbit target at version 6.1.10 due to this issue:
> https://github.com/microsoft/pxt-microbit/pull/5481


#### Metadata (used for search, rendering)

* for PXT/
<script src="https://makecode.com/gh-pages-embed.js"></script><script>makeCodeRender("{{ site.makecode.home_url }}", "{{ site.github.owner_name }}/{{ site.github.repository_name }}");</script>
