#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main (void)
{
    printf ("Connecting to hello world server\n");
    void *context = zmq_ctx_new ();
    void *requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "http://127.0.0.1:12345");

    char buffer [10];
    printf ("Sending Hello\n");
    zmq_send (requester, "Hello", 5, 0);
    zmq_recv (requester, buffer, 10, 0);
    printf ("Received %s\n", buffer);

    zmq_close (requester);
    zmq_ctx_destroy (context);
    return 0;
}
