# Brewery-Control

Arduino based projects to control an electric brewery

## Projects

### Boil_Kettle

A simple PWM of very low frequency to control a CAMCO 5500W 240VAC heating element

## Hacking

Obtain the source and [Sudar Muthu's excellent `Makefile`](https://github.com/sudar/Arduino-Makefile/).

```
git clone https://github.com/kostecky/Brewery-Control
cd Brewery-Control
git submodule init
git submodule update
```

### Building

Each project should have a `Makefile` that calls the main `Makefile`:

```
ARDMK_DIR = ../Arduino-Makefile

include $(ARDMK_DIR)/Arduino.mk
```

Then, build or upload the sketch using the `build` script:

```
./build Boil_Kettle upload
```

### Bash completion

The `build` script supports Bash completion. To enable it,


1. Install `bash-completion` 2+.

  * Debian/Ubuntu:

    ```
    sudo apt-get install bash-completion
    ```

  * Red Hat / CentOS:

    ```
    sudo yum install bash-completion
    ```

  * Mac OS X:

    ```
    brew install bash-completion2
    ```

2. Source the `build` script and run it.

    ```
    . build
    ./build <TAB>
    ```
