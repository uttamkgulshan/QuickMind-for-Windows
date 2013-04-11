//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

USEFORM("GameBoard.cpp", Form1);
USEFORM("ScoreBoard.cpp", ScoreBoard);


//---------------------------------------------------------------------------


WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

		try
		{

				 Application->Initialize();

				 Application->CreateForm(__classid(TForm1), &Form1);
		Application->Run();

		}
		catch (Exception &exception)
		{
				 Application->ShowException(&exception);
		}

		catch (...)
		{
				 try
				 {
						 throw Exception("");
				 }
				 catch (Exception &exception)
				 {
						 Application->ShowException(&exception);
				 }
		}

		return 0;
}

//---------------------------------------------------------------------------
