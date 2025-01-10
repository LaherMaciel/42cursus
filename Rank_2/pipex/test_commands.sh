< infile.txt grp a1 | wc -w > outfile.txt
< infile.txt grep a1 | wh -w > outfile.txt
< infile.txt greep --w | wc -w > outfile.txt
< infile.txt grep --w | wc -w > outfile.txt
./pipex infile.txt "grp a1" "wc -l" pipex_outfile.txt
./pipex infile.txt "grep a1" "wh -l" pipex_outfile.txt
./pipex infile.txt "greep --w" "wc -l" pipex_outfile.txt
./pipex infile.txt "grep --w" "wc -l" pipex_outfile.txt
