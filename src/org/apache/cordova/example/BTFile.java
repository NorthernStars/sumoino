import java.io.IOException;
import java.io.FileReader;
import java.io.BufferedReader;

public class BTFile 
{
	private String path;
	public BTFile(String file_path)
	{
		path=file_path;
	}
	
	
	
	//public class filedata
	//{
		public static void main(String[] args) throws IOException
		{
		String file_name="c:/Blink.hex";
		//System.out.println("kala");
		try
		{
			BTFile file = new BTFile( file_name );
			String[ ] aryLines = file.OpenFile( );
			
			System.out.println(file.OpenFile());
		}
		catch ( IOException e ) 
		{
			System.out.println( e.getMessage() );
		}
		
		}
//	}
	
	
	
	
	
	public String[] OpenFile() throws IOException
	{
		
		
		
		FileReader Fr= new FileReader(path);
		BufferedReader textReader=new BufferedReader(Fr);
		int numberOfLines = readLines( );
		String[ ] textData = new String[numberOfLines];
		
		int i;

		for (i=0; i < numberOfLines; i++) {
		textData[ i ] = textReader.readLine();
		System.out.println(textData[i]);
		}
		
		textReader.close( );
		
		return textData;
		
	}
	
	int readLines() throws IOException
	{
		
	FileReader file_to_read= new FileReader (path);
	BufferedReader bf= new BufferedReader(file_to_read);
	String aLine;
	int numberOfLines=0;
	while((aLine=bf.readLine()) != null)
	{
			numberOfLines++;
	}
	bf.close();
	return numberOfLines;
	
	}
	
}
