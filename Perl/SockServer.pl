use IO::Socket::INET;

my $socket = new IO::Socket::INET (
    LocalHost => '0.0.0.0',
    LocalPort => '9000',
    Proto => 'tcp',
    Listen => 10,
    Reuse => 1
);
die "cannot create socket\n" unless $socket;

my $client_socket = $socket->accept();

my $data = "";
$client_socket->recv($data, 1024);
print "received data: $data\n";

$data = "ok";
$client_socket->send($data);

$socket->close();
