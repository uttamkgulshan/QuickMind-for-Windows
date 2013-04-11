//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TScoreBoard : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TLabel *OutcomeLabel1;
        TLabel *ScoreLabel;
        TTimer *Timer1;
        TLabel *OutcomeLabel2;
        TLabel *Label1;
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Image1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TScoreBoard(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TScoreBoard *ScoreBoard;
//---------------------------------------------------------------------------
#endif
