#include <unistd.h>

int main() {

	int p[2];
	char *argv[2];
	argv[0] = "wc";
	argv[1] = 0;
	pipe(p);
	if(fork() == 0) {
		close(0);
		dup(p[0]);
		close(p[0]);
		close(p[1]);
		execl("/bin/wc", argv);
	} else {

		close(p[0]);
		write(p[1], "hello world\en", 12);
		close(p[1]);
	}
}
