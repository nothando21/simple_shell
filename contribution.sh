#!/bin/bash
set -e

{
cat <<-'EOF'
# This file lists all individuals having contributed content to the repository.
EOF
echo
git log --format='%aN <%aE>' | grep -v "github.com"
} > Authors
