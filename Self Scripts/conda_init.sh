# >>> conda initialize >>>
# !! Contents within this block are managed by 'conda init' !!
__conda_setup="$('/run/media/coderdude/adth/arch/anaconda/installed/anaconda3/bin/conda' 'shell.bash' 'hook' 2> /dev/null)"
if [ $? -eq 0 ]; then
    eval "$__conda_setup"
else
    if [ -f "/run/media/coderdude/adth/arch/anaconda/installed/anaconda3/etc/profile.d/conda.sh" ]; then
        . "/run/media/coderdude/adth/arch/anaconda/installed/anaconda3/etc/profile.d/conda.sh"
    else
        export PATH="/run/media/coderdude/adth/arch/anaconda/installed/anaconda3/bin:$PATH"
    fi
fi
unset __conda_setup
# <<< conda initialize <<<