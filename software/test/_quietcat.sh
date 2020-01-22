#!/bin/bash
set -e

if [ -f "$1" ]; then
    cat "$1" | sed -e "s|^[^:]*:||g" -e "s|\\\\| |g" | tr -d "\n"
fi
