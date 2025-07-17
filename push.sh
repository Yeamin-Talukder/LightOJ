#!/bin/bash

# Ensure Git is initialized
if ! git rev-parse --git-dir > /dev/null 2>&1; then
  echo "Not a git repository. Initialize one with 'git init'"
  exit 1
fi

# Stage all modified and new files
git add .

# Use safer while-read loop to preserve spaces and special characters
git diff --cached --name-only -z | while IFS= read -r -d '' file; do
  # Get filename without extension
  filename=$(basename "$file")
  name="${filename%.*}"

  # Commit with proper quoting
  git commit -m "Add $name" "$file"
done

# Push to current branch
git push
