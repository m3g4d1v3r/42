#!/bin/sh
find -name "*.sh" | sed -E 's/^.*\/(.*)\.sh/\1/g'
