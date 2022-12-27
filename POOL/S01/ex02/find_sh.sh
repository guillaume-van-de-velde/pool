find -type f -name "*.sh" | awk -F '[/.]' '{print $(NF - 1)}'
