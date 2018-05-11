#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "TFile.h"
#include "TTree.h"
#include "TMath.h"

using namespace std;
#define Pi_180 0.01745329251994

int szer_Clustra(){
	TRandom2 rnd(0);
	Double_t r=rnd.Uniform(0,1);
	int szer=0;
	Double_t progi[]={0.6,0.975,0.992,0.9976,0.9989};
	for(int k=0;k<sizeof(progi)/sizeof(*progi);k++){
		if(r<progi[k]){
			szer=k;
			break;
		}
	}
	return szer;
}
int ktoryNumFi(int dfi){

	int wynik=-1;
	int k=0;
	for(int i=0;i<18;i++){
		k=(i+1)*2;
		if(dfi>(k-1) && dfi<(k+1)){
			wynik=i;

		}
		if(i==17 && dfi<1)
		{
			wynik=i;

		}
	}
	return wynik;
}
int Konfig_eff_4_all() {
	gStyle->SetPadBottomMargin(0.12);
	gStyle->SetPadLeftMargin(0.12);
	ifstream stream1;
	char file1[200];
	char nazwa[200];
	char nazwa2[200];
	int col=15;
	float wiersz[col];
	int numery_plikow1[]={19,23,17,25};
	int numery_plikow2[]={25,23,29,29};
int num1;
int num2;
fstream wyniki;
TCanvas *c2 = new TCanvas("c2","srednie wydajnosci",200,10,700,600);
c2->Divide(2,2);
   wyniki.open("./Wyniki/Wyniki_calosc.txt", ios::app | ios::out );
   if( wyniki.good() == true )
   {

	for(num1=0;num1<4;num1++){
	num2=num1;
	cout<<"kolejna iteracja\n";
		sprintf(file1,"./%d_%d_ppn/Bina_out1.dat",numery_plikow1[num1],numery_plikow2[num2]);
		cout <<"Otwieranie pliku \n";
		cout<<file1<<"\n";
	    stream1.open(file1);
		if(stream1.good()){
	TFile *f;
	TTree *geant = new TTree("sym","symulacja");
	for (int i = 0; i < col; i++) 
	  {
	    char name [6];
	    char name1 [6];
	    sprintf(name, "col%d", i);
	    sprintf(name1, "col%d", i);
	    geant->Branch(name, &wiersz[i], name1);
	  }
	sprintf(nazwa2,"./Wyniki/Symulacja_%d_%d.root",numery_plikow1[num1],numery_plikow2[num2]);
	f = new TFile(nazwa2,"RECREATE");

		cout<<file1<<"\n";
			
	    while(!stream1.eof()) {

	      for (int i = 0; i < col; i++){

		stream1>>wiersz[i];	
		}
	      geant->Fill();
	    }		
	    cout <<"Zamykanie pliku \n";
	    stream1.close();
if(num1!=num2){
	
	sprintf(file1,"./%d_%d_ppn/Bina_out1.dat",numery_plikow1[num2],numery_plikow2[num1]);
	 stream1.open(file1);
	if(stream1.good()){
			cout<<"druga konfiguracja \n";
			cout<<file1<<"\n";
	while(!stream1.eof()) {
	      for (int i = 0; i < col; i++){
		stream1>>wiersz[i];
		}
	      geant->Fill();
	    }
	}
	stream1.close();
}
	geant->Write();
	cout << "koniec wczytywania\n";
	TH2F *h= new TH2F("histogram","MWPC",400,-200,200,400,-200,200);
	TH1F *histEv= new TH1F("EvHist","ilosc czastek w evencie",5,0,5);
	TH1D *histOdl= new TH1D("OdlHist","histogram odleglosci miedzy czastkami",400,0,400);
	TH1F *ODX= new TH1F("ODX","Czastka w plaszczyznie X",236,-193,193);
	TH1F *ODY= new TH1F("ODY","Czastka w plaszczyznie Y",236,-193,193);
	TH1F *ODU= new TH1F("ODU","Czastka w plaszczyznie U",296,-273,273);
	TH1F *ODXYU= new TH1F("ODXYU","odleglosc pomiedzy drutami",300,0,300);
	TH1F *Th= new TH1F("Th","MWPC Theta",30,10,40);
	TH1F *Phi= new TH1F("Phi","MWPC Phi",72,-180,180);
Double_t progi[]={0.6,0.975,0.992,0.9976,0.9989};
Double_t szer[]={1,2,3,4,5};
Int_t li=5;
	TH1F *U= new TH1F("U","wartosci U",300,0,300);
	int Entr=geant->GetEntries();
	geant->GetEntry(0);
	float staryEv=wiersz[0];
	int licznik=0;
	float nowyEv;
	float x [5];
	float det[5];
	float id[5];
	float y[5];
	float u[5];
	float fZ=297;
	double kat=TMath::Pi()/4;
	geant->GetEntry(0);
	staryEv=wiersz[0];
	vector <float> Event [8];
	int E[5];
	int dE[5];
	int Xbin[5];
	int Ybin[5];
	int Ubin[5];
	int Enum[5];
	short PhiBin[5];
	short ThBin[5];
	int j=0;
	int k=0;
	int bajt;
	int bajtX;
	int bajtY;
	int bajtU;
	TTree * an=new TTree("analiza","analiza eventow");
	int analiza [12];
	int dfi;
	int dth;
	int idfi;
	Long_t Wszystkie=0;
	Long_t Dobre=0;
short HubX=0;
short HubY=0;
short HubU=0;
	an->Branch("Ev",&analiza[0],"Ev/I");
	an->Branch("ID",&analiza[1],"ID/s");
	an->Branch("bajt",&analiza[2],"bajt/s");
	an->Branch("Xbin",&analiza[3],"Xbin/s");
	an->Branch("Ybin",&analiza[4],"Ybin/s");
	an->Branch("Ubin",&analiza[5],"Ubin/s");	
	an->Branch("ThBin",&analiza[6],"ThBin/I");
	an->Branch("PhiBin",&analiza[7],"PhiBin/s");
	an->Branch("Dphi",&dfi,"DPhi/s");
	an->Branch("DTh",&dth,"DTheta/s");
	an->Branch("HubX",&HubX,"HubX/s");
	an->Branch("HubY",&HubY,"HubY/s");
	an->Branch("HubU",&HubU,"HubU/s");
	an->Branch("PhiBin0",&analiza[8],"PhiBin0/s");
	an->Branch("PhiBin1",&analiza[9],"PhiBin1/s");
	an->Branch("E0",&analiza[10],"E0/s");
	an->Branch("E1",&analiza[11],"E1/s");
int DeadGod=0;


//flagi On
short DeadWiresOn=1;
short IsHubOn=1;

short EisOn=1;
short dEisOn=1;
short ClusterIsOn=1;

short XhubMin=94;
short YhubMin=94;
short UhubMin=118;
short XhubMax=141;
short YhubMax=141;
short UhubMax=178;
short XhubMean=118;
short YhubMean=118;
int Xbad []={95,96,97,118,119,120,128,129,130,131,132,159,160,161,162,163};
int Ybad []={32,33,34,120,121,122,160,161,162};
int Ubad []={50,51,52,224,225,226,227,228,277,278,279};
int test2=1;
int idfimax=18;
Long_t fi_good[18][75];
Long_t fi_all[18][75];
Double_t fi_niep[18][75];
Double_t fi_wyd[18][75];
Double_t ndfi[18];
Long_t fi_good_srednie[18];
Long_t fi_all_srednie[18];
Double_t fi_niep_srednie[18];
Double_t fi_wyd_srednie[18];

for(int i=0;i<idfimax;i++){
	for(int j=0;j<75;j++){
		fi_good[i][j]=0;
		fi_all[i][j]=0;
		fi_niep[i][j]=0;
		fi_wyd[i][j]=0;
		}
		ndfi[i]=0;
		fi_good_srednie[i]=0;
		fi_all_srednie[i]=0;
		fi_niep_srednie[i]=0;
		fi_wyd_srednie[i]=0;
}
for(Long_t i=0; i<Entr; i=i+3){

		geant->GetEntry(i+1);	
	
if(i>(Entr-10)) {
cout<<j<<"\n";
cout<<i<<"\n";
}
				id[0]=wiersz[1];
				det[0]=wiersz[2];
				E[0]=wiersz[12];
				x[0]=wiersz[5];
				y[0]=wiersz[6];
				u[0]=x[0]*cos(kat)+y[0]*sin(kat);
				dE[0]=wiersz[8];

		geant->GetEntry(i+2);

				id[1]=wiersz[1];
				det[1]=wiersz[2];
				E[1]=wiersz[12];
				x[1]=wiersz[5];
				y[1]=wiersz[6];
				u[1]=x[1]*cos(kat)+y[1]*sin(kat);
				dE[1]=wiersz[8];
	if(id[0]==2 && id[1]==2 && det[0]==1 && det[1]==1){
for(j=0;j<2;j++){
			Wszystkie++;
				Xbin[j]=ODX->Fill(x[j]);
				Ybin[j]=ODY->Fill(y[j]);
				Ubin[j]=ODU->Fill(u[j]);
				ThBin[j]=(short)Th->Fill(atan2f(sqrt(x[j]*x[j]+y[j]*y[j]),fZ)/Pi_180);
				PhiBin[j]=(short)Phi->Fill(atan2f(x[j],y[j])/Pi_180);


		}
		bajt=0;
		bajtX=0;
		bajtY=0;
		bajtU=0;
		dfi=0;
		dth=0;
		HubX=0;
		HubY=0;
		HubU=0;
		idfi=0;		

		dfi=abs(PhiBin[0]-PhiBin[1]);
		if(dfi>36) dfi=72-dfi;
		dfi=abs(dfi);
		
		idfi=ktoryNumFi(dfi);
		if(idfi>-1) {		
		fi_all[idfi][PhiBin[0]]++;
		}
		if(ClusterIsOn==1){
		if(IsHubOn==1){
		if(abs(Xbin[0]-Xbin[1])<(szer_Clustra()+1)){
			bajtX |=0x10;
			bajtX |=0x01;			

			if(Xbin[0]>XhubMin && Xbin[0]<XhubMax && Ybin[0]>YhubMean)
			{
				HubX=1;
			}
			if(Xbin[1]>XhubMin && Xbin[1]<XhubMax && Ybin[1]>YhubMean)
			{
				if(HubX==1) {
				HubX=0;
				bajtX |=0x20;
				}
				else {HubX=1;
				bajtX=0;
				}
			}
			if(test2==1){
			for(int g=TMath::Min(Xbin[0],Xbin[1]);g<TMath::Max(Xbin[0],Xbin[1]);g++){
				for(int l=0;l<sizeof(Xbad)/sizeof(*Xbad);l++){
					if(g==Xbad[l]){
						bajtX=0;
					}
				}
			}
				
			}
			
		}
		if(abs(Ybin[0]-Ybin[1])<(szer_Clustra()+1)){
			bajtY |=0x10;
			bajtY |=0x02;

			if(Ybin[0]>YhubMin && Ybin[0]<YhubMax && Xbin[0]>XhubMean)
			{
				HubY=1;
			}
			if(Ybin[1]>YhubMin && Ybin[1]<YhubMax && Xbin[1]>XhubMean)
			{
				if(HubY==1) {
				HubY=0;
				bajtY |=0x40;
				}
				else {HubY=1;
					bajtY=0;
				}
			}
			if(test2==1){
			for(int g=TMath::Min(Ybin[0],Ybin[1]);g<TMath::Max(Ybin[0],Ybin[1]);g++){
				for(int l=0;l<sizeof(Ybad)/sizeof(*Ybad);l++){
					if(g==Ybad[l]){
						bajtY=0;
					}
				}
			}
			}
		
		}
		if(abs(Ubin[0]-Ubin[1])<(szer_Clustra()+1)){
			bajtU |=0x10;
			bajtU |=0x04;	

			if(Ubin[0]>UhubMin && Ubin[0]<UhubMax && Xbin[0]<XhubMean && Ybin[0]>YhubMean)
			{
				HubU=1;
			}
			if(Ubin[1]>UhubMin && Ubin[1]<UhubMax && Xbin[1]<XhubMean && Ybin[1]>YhubMean)
			{
				if(HubU==1) {
				HubU=0;
				bajtU |=0x80;
				}
				else {HubU=1;
					bajtU=0;
				}
			}
			if(test2==1){
			for(int g=TMath::Min(Ubin[0],Ubin[1]);g<TMath::Max(Ubin[0],Ubin[1]);g++){
				for(int l=0;l<sizeof(Ubad)/sizeof(*Ubad);l++){
					if(g==Ubad[l]){
						bajtU=0;
					}
				}
			}
			}
			}	
		}		
		else
		{

		if(abs(Xbin[0]-Xbin[1])<(szer_Clustra()+1)){
			bajtX |=0x10;
			bajtX |=0x01;			
		}
		if(abs(Ybin[0]-Ybin[1])<(szer_Clustra()+1)){
			bajtY |=0x10;
			bajtY |=0x02;
		
		}
		if(abs(Ubin[0]-Ubin[1])<(szer_Clustra()+1)){
			bajtU |=0x10;
			bajtU |=0x04;	
			}	
		}
		}
		bajt=bajtX|bajtY|bajtU;	
		if(EisOn==1 && E[0]==E[1]) bajt |=0x100;
		if(dEisOn==1 && dE[0]==dE[1]) bajt |=0x100;

			for(j=0;j<2;j++){
				if(DeadWiresOn==1){
				
				for(k=0;k<sizeof(Xbad)/sizeof(*Xbad);k++){
					if(Xbin[j]==Xbad[k]){
						DeadGod=1;
						break;
					}
				}
				for(k=0;k<sizeof(Ybad)/sizeof(*Ybad);k++){
					if(Ybin[j]==Ybad[k]){
						DeadGod=1;
						break;
					}
				}
				for(k=0;k<sizeof(Ubad)/sizeof(*Ubad);k++){
					if(Ubin[j]==Ubad[k]){
						DeadGod=1;
						break;
					}
				}

		}
		}

		if(DeadGod==0){
for(int z=0;z<2;z++){
			analiza[0]=id[z];
			analiza[1]=det[z];
			analiza[2]=bajt;
			analiza[3]=Xbin[z];
			analiza[4]=Ybin[z];
			analiza[5]=Ubin[z];	
			analiza[6]=ThBin[z];
			analiza[7]=PhiBin[z];	
			analiza[8]=PhiBin[0];
			analiza[9]=PhiBin[1];
			analiza[10]=E[0];
			analiza[11]=E[1];
			an->Fill();		
}			
		if(idfi>-1) {		
			if(bajt==0) fi_good[idfi][PhiBin[0]]++;
		}
		if(bajt==0) Dobre=Dobre+2;
		}
		
	DeadGod=0;

}
		
	}

	cout<<" koniec analizy \n";
	cout<<"Wszystkie= "<<Wszystkie<<" Dobre= "<<Dobre<<" Wydajnosc= "<<(double)Dobre/Wszystkie<<"\n";
	f->Write();
	Double_t S_a;
	Double_t S_g;
fstream plik;
sprintf(nazwa,"./Wyniki/Wynik_%d_%d.txt",numery_plikow1[num1],numery_plikow2[num2]);
   plik.open( nazwa, ios::trunc | ios::out );
   if( plik.good() == true )
   {
		cout<<"Eff i Niepewnosci\n";
	int np=0;
	for(int i=0;i<idfimax;i++){
		for(int j=0;j<75;j++){
			if(fi_good[i][j]>0){
			fi_good_srednie[i]+=fi_good[i][j];
			fi_all_srednie[i]+=fi_all[i][j];
			ndfi[i]=(i+1)*10;
			fi_wyd[i][j]=(double)fi_good[i][j]/fi_all[i][j];
			S_g=sqrt(fi_good[i][j]);
			S_a=sqrt(fi_all[i][j]);
			fi_niep[i][j]=sqrt((S_g/(S_a*S_a))*(S_g/(S_a*S_a))+((S_g*S_g)/(S_a*S_a*S_a))*((S_g*S_g)/(S_a*S_a*S_a)));
			
			wyniki<<numery_plikow1[num1]<<"	"<<numery_plikow2[num2]<<" "<<j*5<<"	"<<(i+1)*10<<"	"<<fi_wyd[i][j]<<"	"<<fi_niep[i][j]<<"\n";
			plik<<numery_plikow1[num1]<<"	"<<numery_plikow2[num2]<<" "<<j*5<<"	"<<(i+1)*10<<"	"<<fi_wyd[i][j]<<"	"<<fi_niep[i][j]<<"\n";
	}
	fi_wyd_srednie[i]=(double)fi_good_srednie[i]/fi_all_srednie[i];
	S_g=sqrt(fi_good_srednie[i]);
	S_a=sqrt(fi_all_srednie[i]);
	fi_niep_srednie[i]=sqrt((S_g/(S_a*S_a))*(S_g/(S_a*S_a))+((S_g*S_g)/(S_a*S_a*S_a))*((S_g*S_g)/(S_a*S_a*S_a)));
	}
	}
	}
	plik.close();
	cout<<numery_plikow1[num1]<<" "<<numery_plikow2[num2]<<"\n";
	
	
	cout<<"koniec iteracji\n";

c2->cd(num1+1);
TGraphErrors *gr=new TGraphErrors();
for(int i=0;i<idfimax;i++){
	gr->SetPoint(i,(i+1)*10,fi_wyd_srednie[i]*100);
	gr->SetPointError(i,0,fi_niep_srednie[i]*100);
}

char title[100];
sprintf(title,"#theta_{1}=%d #theta_{2}=%d",numery_plikow1[num1],numery_plikow2[num2]);
		   gr->SetMarkerColor(4);

 		  gr->SetMarkerStyle(21);
  		 gr->SetTitle(title);
  		 gr->GetXaxis()->SetTitle("#Delta #phi [#circ]");
 	  gr->GetYaxis()->SetTitle("#epsilon [%]");
		gr->GetYaxis()->SetTitleSize(0.075);
		gr->GetXaxis()->SetTitleSize(0.075);
		gr->GetYaxis()->SetLabelSize(0.055);
		gr->GetXaxis()->SetLabelSize(0.055);
		gr->GetYaxis()->SetTitleOffset(0.8);
		gr->GetXaxis()->SetTitleOffset(0.8);	
		gr->Draw("ALP");

		gr->SetMinimum(50);
		gr->SetMaximum(90);
        plik.close();
	}
	}
	
	}
	wyniki.close();

	return 0;
}

