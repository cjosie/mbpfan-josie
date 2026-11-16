# mbpfan-josie

This is my fork of [mbpfan](https://github.com/linux-on-mac/mbpfan), itself an enhanced version of [Allan McRae mbpfan](http://allanmcrae.com/2010/05/simple-macbook-pro-fan-daemon/).

This fork is focused on Gentoo (I use OpenRC, but SystemD should work as well) with pre-T2 era Intel Macs. My current machine is a MacBook Pro 11,4 (Retina 15", mid-2015), so that's what I test on. The board is a Mac-06F11FD93F0323C5, the i7 4770HQ/16GB RAM/Intel Iris Pro 5200 one (I swapped out the stock Radeon dGPU one due to issues at the time with older AMD cards on Linux).

You will need the `applesmc` and `coretemp` kernel modules loaded. These should be loaded by default unless you're running a stripped kernel and forgot to include them.

## Commands:

Execute these as root, or prepend `doas`, `sudo`, or whatever "elevate this command" utility you use. 

## Build

```sh
make
```

This produces `bin/mbpfan` and `bin/mbpfan-tests`.

## Install

```sh
make install
```

Installs:

- `/usr/sbin/mbpfan`
- `/etc/mbpfan.conf`
- `/etc/init.d/mbpfan` (OpenRC)
- `/etc/modules-load.d/mbpfan.conf`
- `/usr/share/doc/mbpfan/README.md`
- `/usr/share/doc/mbpfan/COPYING`
- `/usr/share/doc/mbpfan/COPYING.LESSER`
- `/usr/share/man/man8/mbpfan.8.gz`

## Run

#### Foreground:

```sh
mbpfan -f
```
Append -v for verbose output.

#### As an OpenRC service:

```sh
rc-service mbpfan start
rc-update add mbpfan default
```

## Notes

AI use: I use LLMs for code generation, troubleshooting, and code assistance. Usually local Qwen instances or DeepSeek via OpenRouter. I am trying to learn C code as I go along. Feel free to take issue with anything I do and ping me via the issues here on github, my personal remote, or the email in AUTHORS.md. 
