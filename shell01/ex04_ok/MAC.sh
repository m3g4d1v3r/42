#!/bin/sh
ifconfig -a | grep ether | sed -E 's/^.*ether (.*)/\1/g'
