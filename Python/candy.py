import matplotlib.pyplot as plt
import numpy as np

# Example data
x = np.linspace(0, 400, 400)
y1 = np.sin(x * 0.05) * 20 + 20
y2 = np.cos(x * 0.05) * 20 + 20
y3 = np.sin(x * 0.05 + 0.5) * 20 + 20
y4 = np.cos(x * 0.05 + 0.5) * 20 + 20

plt.figure(figsize=(10, 5))
plt.plot(x, y1, label='HIST vol', linestyle='-', color='#1f77b4', linewidth=2)
plt.plot(x, y2, label='roll 3-mins BV vol', linestyle='--', color='#ff7f0e', linewidth=2)
plt.plot(x, y3, label='roll 30-mins BV vol', linestyle='-.', color='#2ca02c', linewidth=2)
plt.plot(x, y4, label='roll approx. vol prod. adj. rets 30 mins', linestyle=':', color='#d62728', linewidth=2)

font = {'family': 'serif', 'color':  'black', 'weight': 'normal', 'size': 16}
plt.title('Volatility Over Time', fontdict=font)
plt.xlabel('Time (minutes)', fontdict=font)
plt.ylabel('Volatility', fontdict=font)
plt.xticks(fontsize=12, fontname='serif')
plt.yticks(fontsize=12, fontname='serif')
plt.grid(True, linestyle='--', linewidth=0.5, alpha=0.7)
plt.legend(loc='upper left', bbox_to_anchor=(1.05, 1), fontsize=12, frameon=True, shadow=True)
plt.savefig('/mnt/data/color_plot.png', format='png', dpi=300)
plt.show()




import matplotlib.pyplot as plt
import numpy as np

# Example data
x = np.linspace(0, 400, 400)
y1 = np.sin(x * 0.05) * 20 + 20
y2 = np.cos(x * 0.05) * 20 + 20
y3 = np.sin(x * 0.05 + 0.5) * 20 + 20
y4 = np.cos(x * 0.05 + 0.5) * 20 + 20

plt.figure(figsize=(10, 5))
plt.plot(x, y1, label='HIST vol', linestyle='-', marker='o', markersize=5, linewidth=2)
plt.plot(x, y2, label='roll 3-mins BV vol', linestyle='--', marker='s', markersize=5, linewidth=2)
plt.plot(x, y3, label='roll 30-mins BV vol', linestyle='-.', marker='^', markersize=5, linewidth=2)
plt.plot(x, y4, label='roll approx. vol prod. adj. rets 30 mins', linestyle=':', marker='*', markersize=5, linewidth=2)

font = {'family': 'serif', 'color':  'black', 'weight': 'normal', 'size': 16}
plt.title('Volatility Over Time', fontdict=font)
plt.xlabel('Time (minutes)', fontdict=font)
plt.ylabel('Volatility', fontdict=font)
plt.xticks(fontsize=12, fontname='serif')
plt.yticks(fontsize=12, fontname='serif')
plt.grid(True, linestyle='--', linewidth=0.5, alpha=0.7)
plt.legend(loc='upper left', bbox_to_anchor=(1.05, 1), fontsize=12, frameon=True, shadow=True)
plt.savefig('/mnt/data/high_contrast_plot.png', format='png', dpi=300)
plt.show()




#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -lt 3 ]; then
    echo "Usage: $0 <directory> <prefix> <command> [additional command arguments...]"
    exit 1
fi

# Assign arguments to variables
DIRECTORY=$1
PREFIX=$2
COMMAND=$3
shift 3  # Shift the first three arguments so that $@ contains additional command arguments

# Loop through all files in the directory with the specified prefix
for FILE in "$DIRECTORY"/"$PREFIX"*; do
    # Extract the date in yyyymmdd format from the filename using grep
    DATE=$(echo "$FILE" | grep -oP '\d{8}')
    
    if [ -n "$DATE" ]; then
        # Format the date to yyyy-mm-dd
        START_DATE=$(echo "$DATE" | sed 's/\(....\)\(..\)\(..\)/\1-\2-\3/')

        # Calculate the end date (next day) using the `date` command
        END_DATE=$(date -I -d "$START_DATE + 1 day")

        # Run the specified command with start and end dates as parameters
        $COMMAND "$START_DATE" "$END_DATE" "$@"
    else
        echo "No valid date found in file: $FILE"
    fi
done




bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -lt 3 ]; then
    echo "Usage: $0 <directory> <prefix> <command> [additional command arguments...]"
    exit 1
fi

# Assign arguments to variables
DIRECTORY=$1
PREFIX=$2
COMMAND=$3
shift 3  # Shift the first three arguments so that $@ contains additional command arguments

# Loop through all files in the directory with the specified prefix
for FILE in "$DIRECTORY"/"$PREFIX"*; do
    # Extract the date in yyyymmdd format from the filename
   




To create a pilot tar file, when the release to pilot needs to be done, need to first, once the PR is approved, which means one of reviewers switches red color to green, then need to squash all the PRs, so basically go to SIGPY scripts, run python squash and then PR number, once you press it, need to input at the top of VS Code the password, because it will ask for it. Then it will squash it, and after that, once go to PR on Bitbucket, you'll see that there is one more commit, and probably all others are gone, and so can click merge, it will merge it, wait some time, they go to TeamCity, and since it's pilot, don't go to SIGPY and then, let's say, UAT, but go to UAT PROD, because pilot and PROD is in PROD. So there, just near run at the top right, click on three dots, select the latest branch, and it probably will not be master, select just the latest branch and latest commit, click on build, wait some time, maybe 30 seconds. And then go to that build number, it will be a table, click the first number in the first column, then go to build log, step 5, and find put nexus, put slash nexus. Ta-ta-ta-ta-ta, tar.gz file, you'll see that the name of tar file is much more cleaner than in pilot, and then just... So that should be, that tar file should be included in the pilot email, and to check that this tar file works, just copy-paste, don't forget to add HTTP or eq-quant server and port in front of this nexus line, paste it into browser, and if it works, it will download. So tar file, maybe it can ask for verification, keep file or not, once you click in the browser, keep, it will download, if not at all, then probably it doesn't work and maybe link needs to be fixed. So instead of HTTP barclays, it's probably eq-quant something-something and the port. Once you create, once you prepend this server or HTTP line to the whole nexus, ta-ta-ta-tar line, and you check that it works, then paste this in the email. Also there should be jira, and also from tar file you can infer application name, and most importantly, the version of the application is version number that got modified in version.py file, which is... in the main directory of that particular app.
