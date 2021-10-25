#1 /bin/bash

make -C .. re && make -C .. clean && clear

rm -f pipex_outfile
rm -f pipe_outfile


../pipex ../. "lsi" "wc -l" outfile #2>>my_error
cat outfile >> pipex_outfile
rm outfile
< ../. lsi  | wc -l > outfile #2>>test_error
cat outfile >> pipe_outfile
rm outfile

../pipex ../. "./lsi" "wc -l" outfile #2>>my_error
cat outfile >> pipex_outfile
rm outfile
< ../. ./lsi  | wc -l > outfile #2>>test_error
cat outfile >> pipe_outfile
rm outfile

../pipex ../. "./lsx" "wc -l" outfile #2>>my_error
cat outfile >> pipex_outfile
rm outfile
< ../. ./lsx  | wc -l > outfile #2>>test_error
cat outfile >> pipe_outfile
rm outfile

../pipex infile "/usr/bin/cat" "wc -l" outfile #2>>my_error
cat outfile >> pipex_outfile
rm outfile
< infile /usr/bin/cat  | wc -l > outfile #2>>test_error
cat outfile >> pipe_outfile
rm outfile

../pipex infile "/usr/bin/catx" "wc -l" outfile #2>>my_error
cat outfile >> pipex_outfile
rm outfile
< infile /usr/bin/catx  | wc -l > outfile #2>>test_error
cat outfile >> pipe_outfile
rm outfile

../pipex infile "cat -s" "wc -l" outfile #2>>my_error
cat outfile >> pipex_outfile
rm outfile
< infile cat -s | wc -l > outfile #2>>test_error
cat outfile >> pipe_outfile
rm outfile

../pipex ../pipex.c "grep c" "wc -l" outfile #2>>my_error
cat outfile >> pipex_outfile
rm outfile
< ../pipex.c grep c | wc -l > outfile #2>>test_error
cat outfile >> pipe_outfile
rm outfile

../pipex ../pipex.c "grep p" "wc -l" outfile #2>>my_error
cat outfile >> pipex_outfile
rm outfile
< ../pipex.c grep p | wc -l > outfile #2>>test_error
cat outfile >> pipe_outfile
rm outfile

../pipex ../pipex.c "grexp p" "wc -l" outfile #2>>my_error
cat outfile >> pipex_outfile
rm outfile
< ../pipex.c grexp p | wc -l > outfile #2>>test_error
cat outfile >> pipe_outfile
rm outfile

diff pipex_outfile pipe_outfile

echo pipex_outfile:
cat pipex_outfile
echo pipe_outfile:
cat pipe_outfile
