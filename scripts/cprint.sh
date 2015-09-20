#!/bin/bash

cprint() {
  local code="\033["

  case "$1" in
    black)  color="${code}0;30m";;
    red)    color="${code}0;31m";;
    green)  color="${code}0;32m";;
    yellow) color="${code}0;33m";;
    blue)   color="${code}0;34m";;
    purple) color="${code}0;35m";;
    cyan)   color="${code}0;36m";;
    white)  color="${code}0;37m";;
    BLACK)  color="${code}1;30m";;
    RED)    color="${code}1;31m";;
    GREEN)  color="${code}1;32m";;
    YELLOW) color="${code}1;33m";;
    BLUE)   color="${code}1;34m";;
    PURPLE) color="${code}1;35m";;
    CYAN)   color="${code}1;36m";;
    WHITE)  color="${code}1;37m";;
    *) local text="$1"
  esac

  [ -z "$text" ] && local text="$color$2${code}0m"
  printf "$text"
}
