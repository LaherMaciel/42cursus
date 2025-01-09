< file1.txt grp a1 | wc -w > file2.txt
./pipex file1.txt "grp a1" "wc -l" file2.txt
< file1.txt grep a1 | wh -w > file2.txt
./pipex file1.txt "grep a1" "wh -l" file2.txt
< file1.txt greep --w | wc -w > file2.txt
./pipex file1.txt "greep --w" "wc -l" file2.txt
< file1.txt grep --w | wc -w > file2.txt
./pipex file1.txt "grep --w" "wc -l" file2.txt
