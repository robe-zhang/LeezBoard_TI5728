#!/bin/bash

if [ -f "/root/.boot1" ]; then
/root/.boot1
rm /root/.boot1
else
/root/.boot2  && rm -rf /root/.boot2 /root/.boot
fi
shutdown -r now
