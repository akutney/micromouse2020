# Development Lifecycle

# 1. Create a branch off of **master**

Name the branch with your first name pre-pended:

    $ git checkout master
    $ git checkout -b <first-name>/<feature-name>

# 2. Write code

There are two main ways to view the code, either using [Atmel Studio 7](https://www.microchip.com/mplab/avr-support/atmel-studio-7) or with a plain text editor, such as [Visual Studio Code](https://code.visualstudio.com/download)

# 3. Commit Changes

Create a commit by first adding all the changes that you would like to commit with `git add` and then commit them all to your current branch with `git commit` Don't forget to add a helpful message!

    $ git add --all
    $ git commit -m "<insert your message here>"

`git log` might be helpful to see a list of your commits (press 'q' to exit)

# 4. Push Commits

Use `git push` to send you new commit to GitHub. The first time you do this on a new branch you will need to link this new local branch with a new branch on GitHub with the following command:

    $ git push --set-upstream origin <branch-name>

Afterwards, you will only ever need to type `git push` to push your commits.

# 5. Create a pull request on GitHub

On the [GitHub](https://github.com/ksurct/micromouse2020), create a pull request by following these steps

1. Open the Pull requests tab
2. Click "New Pull Request"
3. Set the "base" branch to master and the compare branch to the one you just pushed
4. Click "Create Pull Request"
5. Keep the default title, but explain what was added within the pull request in the comment
6. If there are any merge conflicts, you will need to first rebase your branch off of master
    - In depth instructions on rebasing can be found [here](https://blog.algolia.com/master-git-rebase/), but it most consists of checking out your branch and running `git rebase master`
7. Bug @dstaatz to review your code and merge it into master