#!/bin/bash

# Ensure a commit message is provided
if [ -z "$1" ]; then
  echo "Error: Commit message is required as the first argument."
  echo "Usage: ./push.sh \"Your commit message\""
  exit 1
fi

# Set the desired committer email
NEW_EMAIL="dyarkovs@student.42wolfsburg.de"

# Ensure git is installed
if ! command -v git &> /dev/null; then
  echo "Error: Git is not installed. Please install it and try again."
  exit 1
fi

# Add changes to staging
echo "Adding changes to staging..."
git add .

# Commit with the specified committer email
echo "Committing with committer email: $NEW_EMAIL"
GIT_COMMITTER_EMAIL="$NEW_EMAIL" git commit -m "$1"

# Push changes
echo "Pushing changes to the repository..."
git push

# Confirmation message
echo "Done! Changes have been pushed with committer email: $NEW_EMAIL."
