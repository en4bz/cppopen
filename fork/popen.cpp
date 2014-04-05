#include <string>
#include <fstream>
#include <ext/stdio_filebuf.h>

#include <wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

class cpopen {
public:
    static constexpr char* CLOSE = "/dev/null";

private:
    int _pid;
    int rcode;
    int stdin = 0;
    int stdout = 1;
    int stderr = 2;
    __gnu_cxx::stdio_filebuf<char>* in_fb;
    __gnu_cxx::stdio_filebuf<char>* out_fb;
    __gnu_cxx::stdio_filebuf<char>* err_fb;

public:
    cpopen(char* cmd, char* stdin = nullptr, char* stdout = nullptr, char* stderr = nullptr) {
        this->_pid = ::fork();
        char* argv[1];
        argv[0] = cmd;
        argv[1] = nullptr;
        if(_pid == 0){
            //Child
            if(stdin != nullptr)
                close(this->stdin);
                if(stdin != CLOSE){
                    this->stdin = open(stdin, O_RDONLY);
                }

            if(stdout != nullptr){
                close(this->stdout);
                this->stdout = open(stdout, O_WRONLY|O_CREAT|O_TRUNC);
            }
            if(stderr != nullptr){
                close(this->stderr);
                this->stderr = open(stderr, O_WRONLY);
            }
            this->rcode = execvp(cmd, argv);
        }
        else{
            out_fb = new __gnu_cxx::stdio_filebuf<char>(this->stdout, std::ios::out);
            err_fb = new __gnu_cxx::stdio_filebuf<char>(this->stderr, std::ios::out);
        }
    }

    int poll(){
        return ::waitpid(this->_pid, &rcode, WNOHANG);
    }

    int wait(){
        return ::waitpid(this->_pid, &rcode, 0);
    }

    int kill(){
        return ::kill(this->_pid, SIGKILL);
    }

    int signal(int signum){
        return ::kill(this->_pid, signum);
    }

    int pid() const {
        return this->_pid;
    }

    int return_code() const {
        return this->rcode;
    }

    ~cpopen(){
        this->kill();
    }
};

int main(int argc, char *argv[]){
    cpopen x("uptime",nullptr,"out.txt");
    x.poll();
    x.wait();
    return 0;
}