#!/bin/bash

# Ensure Git is initialized
if ! git rev-parse --git-dir > /dev/null 2>&1; then
  echo "Not a git repository. Initialize one with 'git init'"
  exit 1
fi

# Stage all modified and new files
git add .

# Loop through all staged files
for file in $(git diff --cached --name-only)
do
  # Get base filename without extension
  filename=$(basename "$file")
  name="${filename%.*}"

  # Commit with custom message
  git commit -m "Add $name" "$file"
done

# Push to current branch
git push
