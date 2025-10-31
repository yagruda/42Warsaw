#include <stdio.h>
#include <unistd.h>

/*
Allowed functions:	close, fork, wait, exit, execvp, dup2, pipe

int    picoshell(char **cmds[]);

Examples: 
./picoshell /bin/ls "|" /usr/bin/grep picoshell
picoshell
./picoshell echo 'squalala' "|" cat "|" sed 's/a/b/g'
squblblb

Как это работает в баше (и что тебе нужно повторить)
pipe() создаёт два конца трубы:
fd[0] — читать
fd[1] — писать
Всё, что записывает один процесс в fd[1], другой может прочитать из fd[0].
fork() создаёт нового ребёнка (копию текущего процесса).
dup2() перенаправляет стандартные потоки:
Чтобы ребёнок читал не из клавиатуры, а из предыдущего пайпа (dup2(pipes[i-1][0], 0))
Или писал не на экран, а в следующий пайп (dup2(pipes[i][1], 1)).
execvp() заменяет текущий процесс на новую программу.
После execvp() старый код не выполняется.

*/

int main(int argc, char** argv)
{

	int fd[2];
	pipe(fd);

	if (argc < 2)
	{
		write(1, "Usage: ./picoshell <command>\n", 29);
		return 1;
	}


	char *const cmds[] = {"ls", "|", "grep", "test", NULL};

	execvp("/bin/ls", cmds);
	return 0;
}