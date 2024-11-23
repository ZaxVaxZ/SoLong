(outside of minishell):
	env -i ./minishell
	echo $SHLVL
	unset SHLVL
	env
	export
	export jksdf
	export a=5
	unset a
	unset jksdf
	unset nothing
	unset
.
/
./
..
//
""
" "
''
' '
>
<
>>
<<
>>>
<<<
echo -nnnnn -nnnnn -nnnnn -n hi -nnn
cat | ls > ls | cat
cat ls
rm ls
export FILENAME=ls
cat | ls >> $FILENAME | cat
sleep 2 | ls
ls | sleep 2
<<"<"<
<< "<" <
<<"<<"
<<$SHLVL
<<test$SHLVL
<<$SHLVL-%
<<"hi$SHLVL"
<<'hi$SHLVL'
touch uwu
chmod 0 uwu
>shouldbethere<uwu>shouldntbe
<shouldbethere>uwu<shouldntprint
exit 1 2 3 4
exit 1 jsd i
exit jksdf
export ajksdf
export asdf = $% $jksdf $jksdf=kjksdf '' " " &% @#
(in heredoc):
	$USER
	$"USER"
	"$USER"
	$U"SER"
	$'USER'
	'$USER'
	$U'SER'