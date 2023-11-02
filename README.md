# prett 🚀

A prettifier for sh commands, inspired by [ptSh](https://github.com/jszczerbinsky/ptSh).

![ls command demo](assets/ls.png)

## Prequisites

- A font that is capable of displaying nerd icons.
- CMake, Ninja, and a C compiler
- A shell (eg.zsh, bash)
- A ansi color-compatible terminal (eg. Alacritty).

## Building

```bash
git clone https://github.com/theoparis/prett
cd prett
cmake -B build -G Ninja`
cmake --build build
```

## Usage

Run `prett sub-command`.

### Compatible Commands

- `ls`

## Shell Aliases

You can optionally alias the default commands in your shell to point to the corresponding prett commands.

See [aliases.sh](scripts/aliases.sh).
