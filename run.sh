#!/bin/bash

# ===================================== FUNCTIONS ===========================================
# Credit: https://github.com/ppo/bash-colors
# To change colors in terminal.
c() { echo "$1" | sed -E "s/(^|[^-_])([krgybmcw])/\1-\2/;s/(^$|0)/!0¡/;s/([BUFNL])/!\1¡/g;s/([-_])([krgybmcw])/!\1\2¡/g;y/BUFN-_krgybmcw/14573401234567/;s/L/22/;s/!/\\\033[/g;s/¡/m/g"; }


#---------------------GLOBAL VARIABLES------------------
input="test.cpp"
output="a.out"
no_mem=0 #default mem check is enables using valgrind.
towatch=$input



# Some usable functions
log(){
    # [CPP RUNNER] in blue and all arguments given to log as cyan.
    echo -e "$(c 0B)[CPP RUNNER]:$(c) $(c 0c)$@$(c)"
}

warn(){
     echo -e "$(c 0B)[CPP RUNNER]:$(c) $(c 0y)$@$(c)"
}

error(){
     echo -e "$(c 0B)[CPP RUNNER]:$(c) $(c 0r)$@$(c)"
}

banner(){
     echo -e "$(c Bg)$@$(c)"
}

help(){
   echo "Use: ./run.sh <flags> [file name to compiled and run]"
    echo ""
    echo "Supported flags:"
    echo "-mf=,--makefile               Pass Makefile (Defaults to Makefile, if opted)"
    echo "-h, --help        See help"
    echo "--no-mem      Disables valgrind"
    echo "-o, --output    Set name of default compiled file name, default is a.out"
    echo "-w, --watch       Set directories to be watched (Multiple are supported if given inside \"\")"
    echo ""
    echo "Example: ./run.sh -w=./atstllib/** --out-file=out main.cpp"
    exit 0
}

close(){
    if [ $# -eq 0 ];then
        log "Exiting with code 0..."
        exit
    else
        local msg="Exiting with code $1"
        if [ $1 -ne 0 ];then error $msg;else log $msg;fi
        exit $1
    fi
}

#makefile in case of multiple files.
assign_makefile(){
    if [ $1 == "" ];then
        makefile="Makefile"
    else makefile=$1
    fi

    #Check if that file exists.
    if ! test -f $makefile;then
        error "Given Makefile doesn't exist!"
        warn "Checking for default \"Makefile\"..."
        if test -f Makefile;then
            makefile="Makefile"
            log "Default \"Makefile\" found.Proceeding..."
        else 
            error "Couldn't find default \"Makefile\". Closing..."
            exit 2
        fi
    fi
}



#to parse the arguments.
parse_args(){
    for i in $@
        do
            VALUE=$(echo $i | awk -F= '{print $2}') #$2 is everything after equals sign.
            case "$i" in
            --no-mem) no_mem=1
            ;;
            -w=* | --watch=*) towatch=$VALUE
            ;;
            -o=* | --output=*) output=$VALUE
            ;;
            -mf=* | --makefile) assign_makefile $VALUE
            ;;
            -h | --help) help 
            ;;
            -* | --*) echo "Invalid Flag. RUN ./run.sh -h to get help."
            ;;
            *) input=$i   
            esac
        done
}

cleanup(){
    log "Cleaning up files"
	rm vgcore.* $output >/dev/null 2>&1
	log "Removed generated files"
}

# THE CPP RUNNER--------------------------------------------------------------------------
#compiles and runs
cpp_runner(){
    log "Compiling..."

    if [ "$makefile" != "" ];then #makefile wasn't set. Compiling single $input
        make -f $makefile
    else 
        clang++ -Wall -std=c++17 -o "$output" $input
    fi

    #In case above process returned non-zero code.
    if [ $? -ne 0 ];then
        error "Failed to compile. Exiting..."
        return 1
    fi
    log "Compilation Successfull!! Executing..."

    #Check if valgrind is there.
    if command -v valgrind >/dev/null 2>&1;then
        if [ $no_mem -ne 0 ];then
            warn "Disabled valgrind. There will be no memory checks.Executing..."
            ./$output
        else valgrind --leak-check=full --track-origins=yes ./$output
        fi
    else 
        warn "Didn't find valgrind.There will be no memory checks. Executing..."
        ./$output
    fi
}



# Execution starts here:

parse_args $@

banner "==================[CPP RUNNER]================="

if command -v inotifywait >/dev/null 2>&1;then
    log "Monitoring changes enabled..."
    log "Watching $towatch for changes..."

    cpp_runner "$@"
    echo ""
    cleanup
    log "Watching $towatch for changes..."

    while inotifywait -q -r -e modify $towatch >/dev/null 2>&1;do
        cpp_runner "$@"
        log "Watching $towatch for changes..."
    done


else 
    log "Monitoring disabled..."
    log "Running executable..."
    cpp_runner "$@"

fi
