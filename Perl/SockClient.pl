use IO::Socket::INET;

my $socket = new IO::Socket::INET (
    PeerHost => '127.0.0.1',
    PeerPort => '9000',
    Proto => 'tcp',
);
die "cannot connect to the server $!\n" unless $socket;

my $data = 'Sock Client Send';
$socket->send($data);

$socket->recv($data, 1024);
print "received data: $data\n";
 
$socket->close();
