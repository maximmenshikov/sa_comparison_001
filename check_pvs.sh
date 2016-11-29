mkdir -p "result_pvs"
make clean
pvs-studio-analyzer trace -o result_pvs/strace_out -- make
pvs-studio-analyzer analyze -f result_pvs/strace_out -l PVS-Studio.lic -o result_pvs/project.log
plog-converter -a GA:1,2 -t tasklist -o result_pvs/project.tasks result_pvs/project.log

