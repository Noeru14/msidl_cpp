import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.net.Socket;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JToolBar;

public class InfSw extends JFrame {
	private static final long serialVersionUID = 1L;
	
	private JTextArea myTextArea = new JTextArea(10, 5);
	private JButton myButton1 = new JButton("Search");
	private JButton myButton2 = new JButton("Play");
	private JButton myButton3 = new JButton("Exit");
	
	JMenuItem myMenuItem11;
	JMenuItem myMenuItem12;
	JMenuItem myMenuItem13;
	
	JButton toolbarB1;
	JButton toolbarB2;
	JButton toolbarB3;
	
	Client client = null;
	
	public InfSw(){
		// size
		this.setPreferredSize(new Dimension(400, 400));
		
		JScrollPane myScrollPane = new JScrollPane(myTextArea);
		
		// myTextArea > center
		myTextArea.setEditable(false);
		this.add(myScrollPane, BorderLayout.CENTER);
		
		//
		MyListener mlt = new MyListener();
		myButton1.addActionListener(mlt);
		myButton2.addActionListener(mlt);
		myButton3.addActionListener(mlt);
		
		// JPanel
		JPanel myJPanel = new JPanel();
		myJPanel.add(myButton1);
		myJPanel.add(myButton2);
		myJPanel.add(myButton3);
		
		// myJPanel >> south
		this.add(myJPanel, BorderLayout.SOUTH);
		
		// JMenu
		JMenuBar myMenuBar = new JMenuBar();
		
		JMenu myMenu = new JMenu("Menu 1");
		myMenuItem11 = new JMenuItem("Search");
		myMenuItem12 = new JMenuItem("Play");
		myMenuItem13 = new JMenuItem("Exit");
		myMenuItem11.addActionListener(mlt);
		myMenuItem12.addActionListener(mlt);
		myMenuItem13.addActionListener(mlt);
		myMenu.add(myMenuItem11);
		myMenu.add(myMenuItem12);
		myMenu.add(myMenuItem13);
		myMenuBar.add(myMenu);

		// JToolBar
		JToolBar myToolbar = new JToolBar();
		myToolbar.setPreferredSize(new Dimension(400, 30));
	    toolbarB1 = new JButton("Search");
	    toolbarB2 = new JButton("Play");
	    toolbarB3 = new JButton("Exit");
		toolbarB1.addActionListener(mlt);
		toolbarB2.addActionListener(mlt);
		toolbarB3.addActionListener(mlt);
	    myToolbar.add(toolbarB1);
	    myToolbar.add(toolbarB2);
	    myToolbar.add(toolbarB3);
	    
		this.add(myToolbar, BorderLayout.NORTH);
		
		// set JMenuBar
		this.setJMenuBar(myMenuBar);
		
		//
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.pack();
		this.setVisible(true);
	}
	
	// listener boutons
	class MyListener implements ActionListener{
		
		public void actionPerformed(ActionEvent e){
			Object source = e.getSource();
			
			if((source == myButton1)||(source == myMenuItem11)||(source == toolbarB1)){
			    sd("1 photo1");
				
				// myTextArea.append("button1 pushed \n");
			}
			else if((source == myButton2)||(source == myMenuItem12)||(source == toolbarB2)){
				sd("2 video1");
				
				// myTextArea.append("button2 pushed \n");
			}
			else if((source == myButton3)||(source == myMenuItem13)||(source == toolbarB3)){
				System.exit(0);
			}
		}
	}
	
	// instanciation fenêtre & client
	public static void main(String[] args){
		InfSw infsw = new InfSw();
		
	    String host = "localhost";
	    int port = 3331;
	    if (args.length >=1) host = args[0];
	    if (args.length >=2) port = Integer.parseInt(args[1]);
	    
	    try {
	      infsw.client = new Client(host, port);
	    }
	    catch (Exception e) {
	      System.out.println("Client: Couldn't connect to "+host+":"+port);
	      System.exit(1);
	    }
	    
	    infsw.myTextArea.append("Client connected to "+host+":"+port);
	    
	    infsw.myTextArea.append("\nWelcome... \n");
	    infsw.myTextArea.append("To display the attributes of a multimdia : please press SEARCH \n");
	    infsw.myTextArea.append("To play a multimedia : please press PLAY \n");
	    infsw.myTextArea.append("To quit without doing anything : please press EXIT \n");
	}
	
	// méthode d'envoi d'une requête selon bouton actionné
	public void sd(String request){
		try{
			String response = this.client.send(request);
			myTextArea.append("\nResponse: " + response);
		}
		catch (Exception e) {
			myTextArea.append("Client: IO error");
			return;
		}
	}

}