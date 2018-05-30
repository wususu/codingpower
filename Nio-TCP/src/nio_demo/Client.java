package nio_demo;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.SocketChannel;
import java.nio.charset.Charset;
import java.util.Iterator;

public class Client {

	
	public static void start(String ip, int port, String destIP, int destPort) throws IOException{
		SocketChannel channel = SocketChannel.open();
		Selector selector = Selector.open();
		
		channel.configureBlocking(false);
//		channel.bind(new InetSocketAddress(ip, port));
		channel.connect(new InetSocketAddress(destIP, destPort));
		channel.register(selector, SelectionKey.OP_CONNECT);  
        
        while(true){  
            if(selector.select()>0){  
                Iterator<SelectionKey> set=selector.selectedKeys().iterator();  

                while(set.hasNext()){  
                    SelectionKey key=set.next();  
                    
                    SocketChannel ch=(SocketChannel) key.channel();  
                    if(key.isConnectable()){  
                        ch.register(selector, SelectionKey.OP_READ | SelectionKey.OP_WRITE,new Integer(1));  
                        ch.finishConnect();  
                    }  
                    
                    if(key.isReadable()){  
                        key.attach(new Integer(1));  
                        ByteBuffer buffer=ByteBuffer.allocate(1024);  
                        StringBuffer sBuffer = new StringBuffer();
                        int len=0;  
                        while((len=ch.read(buffer)) > 0){ 
                            buffer.flip();  
				            String receivedString = Charset.forName("UTF-8").newDecoder().decode(buffer).toString();  
				            sBuffer.append(receivedString);
                            buffer.clear();  
                        }
                        System.out.println(sBuffer.toString());  
                    }  
                      
                    if(key.isWritable()){  
                        key.attach(new Integer(1));  
                        ch.write(ByteBuffer.wrap((("This is my home work, I am happy")).getBytes()));  
                    }
                } 
            }
        }
		
	}
}
