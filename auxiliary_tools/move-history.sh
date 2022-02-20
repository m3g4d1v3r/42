#!/bin/sh
if [ $# -eq 1 ]
  then
    git remote add localrepo $1
    git fetch localrepo
    git merge localrepo/master --allow-unrelated-histories
    git remote rm localrepo
fi
