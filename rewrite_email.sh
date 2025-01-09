#!/bin/bash

# Ensure git-filter-repo is installed
if ! command -v git-filter-repo &> /dev/null; then
  echo "Error: git-filter-repo is not installed."
  echo "Install it using: sudo apt install git-filter-repo (Linux) or brew install git-filter-repo (macOS)."
  exit 1
fi

# Set the replacement email
NEW_EMAIL="dyarkovs@student.42wolfsburg.de"

# Check if the script is in a Git repository
if ! git rev-parse --is-inside-work-tree &> /dev/null; then
  echo "Error: This script must be run inside a Git repository."
  exit 1
fi

# Rewrite history
echo "Rewriting committer emails ending with '42wolfsburg.de'..."
git filter-repo --commit-callback '
if commit.committer_email.endswith("42wolfsburg.de"):
    commit.committer_email = "'"$NEW_EMAIL"'"
'

# Confirm success
echo "Done! The committer emails have been updated to $NEW_EMAIL where applicable."
echo "Force push the changes to your remote repository with: git push --force"
