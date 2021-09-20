# Ensuring that everything is up-to-date
git submodule sync --recursive
git submodule update --init --recursive
git submodule foreach git pull origin master

# Set variables
export FOLDER_SOURCE="${FOLDER_SOURCE:-"$( cd "$(dirname "$0")" ; pwd -P )"/..}"
export FOLDER_BUILD="${FOLDER_SOURCE}/build"

# Configure
cmake --no-warn-unused-cli ..
cmake --build "${FOLDER_BUILD}" -- -j$(nproc)
