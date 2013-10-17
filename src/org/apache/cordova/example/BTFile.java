package org.apache.cordova.example;

import java.io.FileWriter;
import java.io.IOException;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.PrintWriter;

public class BTFile {

	private String path;
	private boolean append_to_file = false;

	public BTFile(String file_path) {
		path = file_path;
	}

	public BTFile( String file_path , boolean append_value ) {
		path = file_path;
		append_to_file = append_value;
	}	

	public static byte[] main() {
		String file_name = "C:/11.txt";	
		BTFile data = new BTFile(file_name,false);
		System.out.println("text file written to ");
		
		file_name = "/sdcard/Blink.hex";
		//System.out.println("kala");
		try {
			data.writeToFile("this is it");
			BTFile file = new BTFile( file_name );
			byte[ ] aryLines = file.OpenFile( );
			return aryLines;
		} catch ( IOException e ) {
			System.out.println( e.getMessage() );
			return null;
		}
	}

	public byte[] OpenFile() throws IOException {
		FileReader Fr = new FileReader(path);
		BufferedReader textReader=new BufferedReader(Fr);
		int numberOfLines = readLines( );
		String textData = new String();

		for (int i = 0; i < numberOfLines; i++) {
			textData += textReader.readLine();
			System.out.println(textData);
		}
		textReader.close( );
		return textData.getBytes();
	}

	int readLines() throws IOException {
		FileReader file_to_read = new FileReader (path);
		BufferedReader bf = new BufferedReader(file_to_read);
		String aLine;
		int numberOfLines = 0;
		while ((aLine = bf.readLine()) != null) {
			numberOfLines++;
		}
		bf.close();
		return numberOfLines;
	}

	public void writeToFile( String textLine ) throws IOException {
		FileWriter write = new FileWriter( path , append_to_file);
		PrintWriter print_line = new PrintWriter( write );
		print_line.printf( "%s" , textLine);
		print_line.close();
	}
}