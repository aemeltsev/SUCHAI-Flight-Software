#!/bin/sh
echo "Installing LibCSP"
cd libcsp
sh install_csp.sh
cd -

echo "Downloading BUS drivers..."
if [ ! -d "suchai-drivers-bus" ]; then
    if [ -z "$SSH_ACTIVE" ]; then
        git clone https://github.com/spel-uchile/suchai-drivers-bus suchai-drivers-bus
    else
        git clone git@github.com:spel-uchile/suchai-drivers-bus.git suchai-drivers-bus
    fi
else
    cd suchai-drivers-bus
    git pull
    cd -
fi

# Dowload linenoise
echo "Installing linenoise..."
if [ ! -d "./linenoise" ]; then
  git clone https://github.com/antirez/linenoise.git
fi
