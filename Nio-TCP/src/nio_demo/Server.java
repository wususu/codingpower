package nio_demo;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.Buffer;
import java.nio.ByteBuffer;
import java.nio.channels.SelectableChannel;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.nio.charset.Charset;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.concurrent.ConcurrentSkipListSet;

public class Server {

	
	public static void start(String ip, int port) throws IOException{
		Selector selector = Selector.open();
		ServerSocketChannel serverSocketChannel = ServerSocketChannel.open();
		serverSocketChannel.bind(new InetSocketAddress(ip, port));
		
		serverSocketChannel.configureBlocking(false);
		serverSocketChannel.register(selector, SelectionKey.OP_ACCEPT);
		
		while(true){
			if (selector.select() == 0) {
				continue;
			}
			
			Set<SelectionKey> selectedKeys = selector.selectedKeys();
			Iterator<SelectionKey> keyIter = selectedKeys.iterator();
			while (keyIter.hasNext()){
				SelectionKey key = keyIter.next(); 
				try{
					if (key.isAcceptable()) {
						SocketChannel channel = ((ServerSocketChannel)key.channel()).accept();
						channel.configureBlocking(false);
						channel.register(key.selector(), SelectionKey.OP_READ, ByteBuffer.allocate(2048));
					}
					
					if (key.isReadable()) {
				        SocketChannel clientChannel = (SocketChannel) key.channel();  
				  
				        ByteBuffer buffer = (ByteBuffer) key.attachment();  
				        buffer.clear();  
				  
				        long bytesRead;
				        while( (bytesRead = clientChannel.read(buffer)) != 0){
				            buffer.flip();  
				  
				            String receivedString = Charset.forName("UTF-8").newDecoder().decode(buffer).toString();  
				            System.out.println(receivedString);
				            SimpleDateFormat format = new SimpleDateFormat("yyyy-mm-dd HH:mm:ss");  
				            String f = format.format(new Date());  
				            String sendString = "MSG Send OK:" + receivedString;  
				            buffer = ByteBuffer.wrap(sendString.getBytes("UTF-8"));  
				            clientChannel.write(buffer);  

				            key.interestOps(SelectionKey.OP_READ | SelectionKey.OP_WRITE);  
				        }
				        clientChannel.close();
					}
					
					if (key.isWritable()) {
					}
				}catch (Exception e) {
					// TODO: handle exception
                    keyIter.remove();
                    continue;
				}
				keyIter.remove();
			}
		}
	}
}
