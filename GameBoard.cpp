//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GameBoard.h"
#include "ScoreBoard.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

#pragma link "TeCanvas"

#pragma resource "*.dfm"


TForm1 *Form1;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
		: TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{

  peg[1][1]=PegA1; peg[1][2]=PegA2; peg[1][3]=PegA3; peg[1][4]=PegA4;
  peg[2][1]=PegB1; peg[2][2]=PegB2; peg[2][3]=PegB3; peg[2][4]=PegB4;
  peg[3][1]=PegC1; peg[3][2]=PegC2; peg[3][3]=PegC3; peg[3][4]=PegC4;
  peg[4][1]=PegD1; peg[4][2]=PegD2; peg[4][3]=PegD3; peg[4][4]=PegD4;
  peg[5][1]=PegE1; peg[5][2]=PegE2; peg[5][3]=PegE3; peg[5][4]=PegE4;
  peg[6][1]=PegF1; peg[6][2]=PegF2; peg[6][3]=PegF3; peg[6][4]=PegF4;
  peg[7][1]=PegG1; peg[7][2]=PegG2; peg[7][3]=PegG3; peg[7][4]=PegG4;
  peg[8][1]=PegH1; peg[8][2]=PegH2; peg[8][3]=PegH3; peg[8][4]=PegH4;


  hint[1][1]=HintA1; hint[1][2]=HintA2; hint[1][3]=HintA3; hint[1][4]=HintA4;
  hint[2][1]=HintB1; hint[2][2]=HintB2; hint[2][3]=HintB3; hint[2][4]=HintB4;
  hint[3][1]=HintC1; hint[3][2]=HintC2; hint[3][3]=HintC3; hint[3][4]=HintC4;
  hint[4][1]=HintD1; hint[4][2]=HintD2; hint[4][3]=HintD3; hint[4][4]=HintD4;
  hint[5][1]=HintE1; hint[5][2]=HintE2; hint[5][3]=HintE3; hint[5][4]=HintE4;
  hint[6][1]=HintF1; hint[6][2]=HintF2; hint[6][3]=HintF3; hint[6][4]=HintF4;
  hint[7][1]=HintG1; hint[7][2]=HintG2; hint[7][3]=HintG3; hint[7][4]=HintG4;
  hint[8][1]=HintH1; hint[8][2]=HintH2; hint[8][3]=HintH3; hint[8][4]=HintH4;

  ResetBoard();

  NewGame();

}

//---------------------------------------------------------------------------



//---------------------------------------------------------------------------

   void TForm1::GenerateCombination() //παράγει το μυστικό συνδυασμό χρωμάτων που θα πρέπει να βρει ο χρήστης.
   {
   //αντιστοίχιση των σχημάτων της φόρμας ShapeX σε στοιχεία του πίνακα mastershape.
   mastershape[1]=Shape1;
   mastershape[2]=Shape2;
   mastershape[3]=Shape3;
   mastershape[4]=Shape4;

   for (int i=1;i<=4;i++) mastershape[i]->Visible=false;
   //αποκρύπτει το μυστικό συνδυασμό από το παίκτη.

   randomize(); //Τροφοδοτεί την γεννήτρια ακεραίων χρησιμοποιώντας το ρολόι του συστήματος.

	 for (int i=1;i<5;i++) //για κάθε i του mastercolor
	 {
	 mastercolor[i]=random(4); //παραγωγή τυχαίου ακεραίου 0-3 για απόδοση χρώματος


	  //απόδοση χρώματος στο κάθε mastershape ανάλογα με τον τυχαίο που παράχθηκε
	  switch( mastercolor[i] )
	  {
	  case 0 :
		mastershape[i]->Brush->Color=clRed;
		break;
	  case 1 :
		mastershape[i]->Brush->Color=clNavy;
		break;
	  case 2 :
		mastershape[i]->Brush->Color=clTeal;
		break;
	  case 3 :
		mastershape[i]->Brush->Color=clPurple;
		break;
	   }
	   //-------------------------------------\\
	 }

   }

//---------------------------------------------------------------------------


 void TForm1::NextTry(int fromtry) //δέχεται ως είσοδο τον αριθμό της
 //προσπάθειας που μόλις έληξε και ετοιμάζει τις παραμέτρους για την μετάβαση στην επόμενη.
 {
	for (int i=1;i<5;i++)
	{
	 peg[fromtry][i]->Enabled=false; //απενεργοποίηση της προηγούμενης σειράς χρωμάτων
	 peg[fromtry+1][i]->Visible=true; //εμφάνιση της επόμενης σειράς χρωμάτων
	}
 }
 //--------------------------------------------------------------------------


void __fastcall TForm1::N5Click(TObject *Sender)
{
 Form1->Close(); //τερματίζει το πρόγραμμα.
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ShapeMouseUp(TObject *Sender, TMouseButton Button,
	  TShiftState Shift, int X, int Y) //με κλικ του χρήστη στο ανάλογο peg
	  //που καθορίζεται από τη boxnum...
{
	clCounter[boxnum]++; //αυξάνει τον αιρθμό χρώματος κατά ένα, σαν αποτέλεσμα...
	if (clCounter[boxnum] > 3) clCounter[boxnum]=0;

	 switch( clCounter[boxnum] ) //αλλάζει χρώμα ακολουθιακά το peg στο οποίο έγινε click.
	 {
	  case 0 :
		peg[currentry][boxnum]->Brush->Color=clRed;
		break;
	  case 1 :
		peg[currentry][boxnum]->Brush->Color=clNavy;
		break;
	  case 2 :
		peg[currentry][boxnum]->Brush->Color=clTeal;
		break;
	  case 3 :
		peg[currentry][boxnum]->Brush->Color=clPurple;
		break;
	 }
}
//---------------------------------------------------------------------------


// Οι παρακάτω 4 συναρτήσεις δίνουν την ανάλογη τιμή 1-4 για κάθε peg στο οποίο ο κάνει κλικ ο χρήστης.
//Έχοντας την τιμή της boxnum η συνάρτηση ShapeMouseUp γνωρίζει σε ποιό από τα 4 pegs
//της σειράς θ' αλλάξει χρώμα.
void __fastcall TForm1::PegA1MouseDown(TObject *Sender,
	  TMouseButton Button, TShiftState Shift, int X, int Y)

{
   boxnum=1;
}

void __fastcall TForm1::PegA2MouseDown(TObject *Sender,
	  TMouseButton Button, TShiftState Shift, int X, int Y)
{
   boxnum=2;
}

void __fastcall TForm1::PegA3MouseDown(TObject *Sender,
	  TMouseButton Button, TShiftState Shift, int X, int Y)
{
   boxnum=3;
}

void __fastcall TForm1::PegA4MouseDown(TObject *Sender,
	  TMouseButton Button, TShiftState Shift, int X, int Y)
{
   boxnum=4;
}
//---------------------------------------------------------------------------



void TForm1::EvaluateMatches()
{
 blackpegs=0;
 whitepegs=0;
 int masterprocessed[5]={false,false,false,false,false};
 int slaveprocessed[5]={false,false,false,false,false};

   //Πρώτα βρίσκονται τα σωστά χρώματα στις σωστές θέσεις
   for (int i=1;i<5;i++)
   {
	 if ( mastercolor[i]==clCounter[i] )
	 {
	  blackpegs++;
	  masterprocessed[i]=true;
	  slaveprocessed[i] =true; //το flag αυτό αποτρέπει τον επανέλεγχο του
	  //κάθε χρώματος του συνδυασμού του παίκτη για λευκά hints σε περίπτωση που ήδη
	  //αποδόθηκε λευκό hint.
	 }
   }
   //----------------------------------------------------\\


   for (int i=1;i<5;i++) //για κάθε clCounter
   {

	 if ( !slaveprocessed[i] ) //μόνο αν στην στήλη i του συνδυασμού παίκτη δεν έχει ανατεθεί black hint...
	 {
	  bool foundmatch=false;

		for (int j=1;j<5;j++) //για κάθε mastercolor
		{
		   if ( !foundmatch & !masterprocessed[j] )
		   {
			  if (mastercolor[j]==clCounter[i])
			  {
				whitepegs++;
				masterprocessed[j]=true;
				foundmatch=true;
			  }
		   }
		} //τέλος for j

	 } //τέλος if(!slaveprocessed)

   } //τέλος for i

}

//---------------------------------------------------------------------------


void TForm1::VisualiseHints()
{

   for (int i=1;i<=blackpegs;i++)
   {
	hint[currentry][i]->Visible=True;
	hint[currentry][i]->Brush->Color=clBlack;
   }

   for (int i=blackpegs+1;i<=(blackpegs+whitepegs);i++)
   {
	hint[currentry][i]->Visible=True;
	hint[currentry][i]->Brush->Color=clWhite;
   }

}



void __fastcall TForm1::Timer1Timer(TObject *Sender)
{

 step--;
  if (step <= 0)
  {
  timer++;
  timeleft--;
  step=7;
  }


   if (timeleft<=0)
   {
    for (int i=1;i<=4;i++) mastershape[i]->Visible=true;
    ScoreBoard->OutcomeLabel1->Caption="Τέλος χρόνου!";
    ScoreBoard->OutcomeLabel2->Caption="Δεν μπορέσατε να βρείτε το μυστικό συνδυασμό σε 8 προσπάθειες.";
    score=0;
    ResetBoard();
    ScoreBoard->Show();
   }

  //καθαρισμός παλέτας
  BombLine->Canvas->Brush->Color=clWhite;
  BombLine->Canvas->Brush->Style=bsSolid;
  BombLine->Canvas->FillRect(Rect(0,0,Width,Height));
//-------------------\\


  //σχεδίαση νήματος
  BombLine->Canvas->Pen->Color=clGray;
  BombLine->Canvas->Pen->Width=3;
  BombLine->Canvas->MoveTo(0,10);
  BombLine->Canvas->LineTo(timeleft,10);
//-------------------\\

  int spark=random(5);

  BombLine->Canvas->Pen->Color=clRed;
	BombLine->Canvas->Pen->Width=1;
//---------------------------Σχεδίαση Σπινθήρων---------------------------------
  BombLine->Canvas->MoveTo(timeleft,10); //κέντρο νήματος
  BombLine->Canvas->LineTo(timeleft-(5+spark),10-(5+spark)); //διαγώνια πάνω αριστερά

  BombLine->Canvas->MoveTo(timeleft,10); //κέντρο νήματος
  BombLine->Canvas->LineTo(timeleft+(5+spark),10-(5+spark)); //διαγώνια πάνω δεξιά

  BombLine->Canvas->MoveTo(timeleft,10); //κέντρο νήματος
  BombLine->Canvas->LineTo(timeleft,0+spark); //πάνω κεντρικά

    BombLine->Canvas->MoveTo(timeleft,10); //κέντρο νήματος
  BombLine->Canvas->LineTo(timeleft,20-spark); //κάτω κεντρικά

    BombLine->Canvas->MoveTo(timeleft,10); //κέντρο νήματος
  BombLine->Canvas->LineTo(timeleft-(5+spark),15+spark); //διαγώνια κάτω αριστερά

  BombLine->Canvas->MoveTo(timeleft,10); //κέντρο νήματος
  BombLine->Canvas->LineTo(timeleft+(5+spark),15+spark); //διαγώνια κάτω δεξιά
//-------------------------------------------------------\\
}


//---------------------------------------------------------------------------


void __fastcall TForm1::N3Click(TObject *Sender)
{
 ShellExecute(NULL,"open","Readme.htm",NULL,NULL,SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::OkImageClick(TObject *Sender)
{

 EvaluateMatches();


 VisualiseHints(); //εμφανίζει τα λευκά ή μαύρα hints στο ταμπλώ τα οποία
                  //υπολογίστηκαν από την EvaluateMatches().

   if (currentry>=8)
   {
    for (int i=1;i<=4;i++) mastershape[i]->Visible=true;
    ScoreBoard->OutcomeLabel1->Caption="Τέλος παιχνιδιού";
    ScoreBoard->OutcomeLabel2->Caption="Δεν μπορέσατε να βρείτε το μυστικό συνδυασμό σε 8 προσπάθειες.";
    score=0;
    ResetBoard();
    ScoreBoard->Show();
   }
   else if (blackpegs<4) NextTry(currentry++);
   else
   {
    for (int i=1;i<=4;i++) mastershape[i]->Visible=true;
    ScoreBoard->OutcomeLabel1->Caption="Συγχαρητήρια!";
    ScoreBoard->OutcomeLabel2->Caption="Βρήκατε το μυστικό συνδυασμό";
    score=(timeleft/3)*(8-currentry);
    ResetBoard();
    ScoreBoard->Show();
   }
}
//---------------------------------------------------------------------------


void TForm1::ResetBoard()
{
  Timer1->Enabled=false;

  //καθαρισμός παλέτας
  BombLine->Canvas->Brush->Color=clWhite;
  BombLine->Canvas->Brush->Style=bsSolid;
  BombLine->Canvas->FillRect(Rect(0,0,Width,Height));
  //-------------------\\

    for (int i=1;i<=8;i++)
    {
      for (int j=1;j<=4;j++)
      {
      peg[i][j]->Visible=false;
      hint[i][j]->Visible=false;
      }
    }
}


void TForm1::NewGame()
{
  currentry=1;
  timer=0;
  timeleft=300;
  step=7;

    for (int j=1;j<=4;j++)
    peg[1][j]->Visible=true;

  Timer1->Enabled=true;
  GenerateCombination(); //συνάρτηση που παράγει το μυστικό συνδυασμό χρωμάτων

}


void __fastcall TForm1::N4Click(TObject *Sender)
{
 NewGame();        
}
//---------------------------------------------------------------------------




