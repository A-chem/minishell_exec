#include "../../../includes/minishell.h"

int ou_cas(t_redirection *ou)
{
    int ou_fd;
    if (ou->type == REDIR_OUT)
		ou_fd = open(ou->file_or_delimiter, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (ou->type == REDIR_APPEND)
		ou_fd = open(ou->file_or_delimiter, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (ou_fd == -1)
	{
		
		perror(ou->file_or_delimiter);
		exit(1);
	}
    if (dup2(ou_fd, 1) == -1)
    {
        perror("minihell: ");
		close(ou_fd);
        exit(1);
    }
	close(ou_fd);
    return 1;
}

void  in_cas(t_redirection *in)
{
    int in_fd;
    if(in->type == REDIR_IN)
    in_fd = open(in->file_or_delimiter, O_RDONLY, 0644);
    if(in_fd == -1)
    {
        write(2, "minihell: ", 11);
		perror(in->file_or_delimiter);
        exit(1);
    }
    close(0);
	if (dup(in_fd) == -1)
	{
		perror("minihell: ");
		close(in_fd);
        exit(1);
    }
    close(in_fd);
}

void inf_outf_cmd(t_simple_cmd **data)
{
    t_redirection *files;

    files =  (*data)->redirs;
    while(files)
    {
        if(files->type == REDIR_IN || files->type == REDIR_HEREDOC)
            in_cas(files);
        else if(files->type == REDIR_OUT || files->type == REDIR_APPEND)
            ou_cas(files);
        files = files->next;
    }
}