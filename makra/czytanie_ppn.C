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
	TCanvas c1;
	float fZ=297;
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
		if(dfi>(k-2) && dfi<=(k)){
			wynik=i;

		}
	}
	return wynik;
}
int czytanie_ppn() {

	ifstream stream1;
	char file1[200];
	char file2[200];
	char PNG[200];
	char nazwa[200];
	char nazwa2[200];
	int col=15;
	float wiersz[col];
	int th1[]={19};
	int th2[]={23};

	int konf=0;
for(konf=0;konf<sizeof(th1)/sizeof(*th1);konf++){
	TFile *F;
	sprintf(file1,"../wyniki/Raw_Sim_ppn_%d_%d.root",th1[konf],th2[konf]);
	F= new TFile(file1,"RECREATE");
	TTree *Raw_Tree=new TTree("Raw","Surowe_wyniki");


		//sprintf(file1,"./%d_%d_ppn/Bina_out1.dat",numery_plikow1[0],numery_plikow1[1]);
		sprintf(file2,"../ppn/%d_%d_ppn/Bina_out1.dat",th1[konf],th2[konf]);

		//sprintf(file2,"/media/menorzinho/TOURO-KHATRI/khatri_2015_phd/phd_package_khatri/khatri_simulation_dd_to_dpn/dd_dpn_sim/%d_%d/Bina_pd_out1.dat",th1[konf], th2[konf]);
		cout <<"Otwieranie pliku \n";
		cout<<file2<<"\n";
		stream1.open(file2);
		if(stream1.good()){
			for (int i = 0; i < col; i++) 
		  	{
		    		char name [6];
		    		char name1 [6];
		    		sprintf(name, "col%d", i);
		    		sprintf(name1, "col%d/f", i);
		    		Raw_Tree->Branch(name, &wiersz[i], name1);
		 	 }	
			while(!stream1.eof()) {

				for (int i = 0; i < col; i++){
					stream1>>wiersz[i];	
				}
				Raw_Tree->Fill();
			}		
			stream1.close();
		}
		else{
		cout<<"File Doesnt Exist\n";
		}
		
		if(th1[konf]!=th2[konf]){
			cout<<"Wczytywanie komplementarnej konfiguracji\n";
			sprintf(file2,"../ppn/%d_%d_ppn/Bina_out1.dat",th2[konf],th1[konf]);
			cout<<file2<<"\n";
			stream1.open(file2);
			if(stream1.good()){
			for (int i = 0; i < col; i++) 
		  	{
		    		char name [6];
		    		char name1 [6];
		    		sprintf(name, "col%d", i);
		    		sprintf(name1, "col%d/f", i);
		    		Raw_Tree->Branch(name, &wiersz[i], name1);
		 	 }	
			while(!stream1.eof()) {

				for (int i = 0; i < col; i++){
					stream1>>wiersz[i];	
				}
				Raw_Tree->Fill();
			}		
			stream1.close();
		
		}
	}
	
	//Raw_Tree->Write();
	//F->Write();
	//F->Close();

//Analiza
	/*
	char parametr[200];
	char warunek[200];
	TCanvas c1;
	sprintf(parametr,"");
	sprintf(warunek,"");
	TH2F *hist_e_e = new TH2F ("hist", "test",200,0,200,200,0,200);

	T->Draw("fEn2:fEn1>>hist",warunek,"colz");
	c1.SaveAs("E1_E2");

	F->Write();
	F->Close();
	
	*/
	TH2F *E_E_hist= new TH2F("E_E_hist","E1 vs E2",200,1,201,200,1,201);
	TH1F *E2_proj= new TH1F("E2_proj","Projekcja energii 1 protonu",200,1,201);
	TH1F *E3_proj= new TH1F("E3_proj","Projekcja energii 2 protonu",200,1,201);
	TH2F *MWPC= new TH2F("MWPC","Polozenie X Y",400,-200,200,400,-200,200);

	TTree *Sorted_Tree=new TTree("Sor","Posortowane_czastki");

	Double_t E1;
	Double_t E2;
	Double_t E3;
	Double_t X1;
	Double_t X2;
	Double_t X3;
	Double_t Y1;
	Double_t Y2;
	Double_t Y3;
	Double_t Th1;
	Double_t Th2;
	Double_t Th3;
	Double_t Phi1;
	Double_t Phi2;
	Double_t Phi3;
	Double_t dPhi;

	Sorted_Tree->Branch("E1",&E1,"E1/D");
	Sorted_Tree->Branch("E2",&E2,"E2/D");
	Sorted_Tree->Branch("E3",&E3,"E3/D");
	Sorted_Tree->Branch("X1",&X1,"X1/D");
	Sorted_Tree->Branch("X2",&X2,"X2/D");
	Sorted_Tree->Branch("X3",&X3,"X3/D");
	Sorted_Tree->Branch("Y1",&Y1,"Y1/D");
	Sorted_Tree->Branch("Y2",&Y2,"Y2/D");
	Sorted_Tree->Branch("Y3",&Y3,"Y3/D");
	Sorted_Tree->Branch("Phi1",&Phi1,"Phi1/D");
	Sorted_Tree->Branch("Phi2",&Phi2,"Phi2/D");
	Sorted_Tree->Branch("Phi3",&Phi3,"Phi3/D");
	Sorted_Tree->Branch("Th1",&Th1,"Th1/D");
	Sorted_Tree->Branch("Th2",&Th2,"Th2/D");
	Sorted_Tree->Branch("Th3",&Th3,"Th3/D");
	Sorted_Tree->Branch("dPhi",&dPhi,"dPhi/D");

	ULong64_t event=0;
	ULong64_t Entries;
	Int_t last_ev_num=0;
int IsProtonAlredyDetect=0;
	Entries=Raw_Tree->GetEntries();
	//cout<<"Entries="<<Entries<<"\n";
	while(event<Entries){
		Raw_Tree->GetEntry(event);
		if(wiersz[0]>last_ev_num){
			dPhi=std::abs(Phi2-Phi3);
			if(dPhi>180) dPhi=360-dPhi;
			if(E2>0 && E3>0 && std::abs(dPhi-150)<5){
			Sorted_Tree->Fill();
			E_E_hist->Fill(E2,E3);
			E2_proj->Fill(E2);
			E3_proj->Fill(E3);
			MWPC->Fill(X2,Y2);
			MWPC->Fill(X3,Y3);
			}
			E1=0;E2=0;E3=0;
			X1=999;X2=999;X3=999;
			Y1=999;Y2=999;Y3=999;
			IsProtonAlredyDetect=0;
		}

		
		switch((int)wiersz[1]){
			case 1:
			E1=wiersz[11];
			X1=wiersz[5];
			Y1=wiersz[6];
			Th1=atan2f(sqrt(X1*X1+Y1*Y1),fZ)/Pi_180;
			Phi1=atan2f(X1,Y1)/Pi_180;
			break;
			case 2:

			
			if(IsProtonAlredyDetect==1){  //niezbyt elegancki trik zeby dostosowac switcha do mozliwosci 2 protonow 
				E3=wiersz[11];
				X3=wiersz[5];
				Y3=wiersz[6];
				Th3=atan2f(sqrt(X3*X3+Y3*Y3),fZ)/Pi_180;
				Phi3=atan2f(X3,Y3)/Pi_180;
			}
			else{
				E2=wiersz[11];
				X2=wiersz[5];
				Y2=wiersz[6];
				Th2=atan2f(sqrt(X2*X2+Y2*Y2),fZ)/Pi_180;
				Phi2=atan2f(X2,Y2)/Pi_180;
			}			
			IsProtonAlredyDetect++;
			
			break;
			case 3:			
			break;
		}

		last_ev_num=wiersz[0];
		event++;
	}
	Sorted_Tree->Write();
	Raw_Tree->Write();
	F->Write();
	c1.Divide(2,2);
	sprintf(PNG,"konfiguracja p1=%d p2=%d",th1[konf],th2[konf]);
	c1.SetTitle(PNG);
	MWPC->GetXaxis()->SetTitle("X czastki");
	MWPC->GetYaxis()->SetTitle("Y czastki");
	c1.cd(1);
	MWPC->DrawCopy("colz");
	//sprintf(PNG,"../wyniki/%d_%d_MWPC.png",th1[konf],th2[konf]);
	//c1.SaveAs(PNG);
	sprintf(PNG,"En proton th=%d",th1[konf]);
	E_E_hist->GetXaxis()->SetTitle(PNG);
	sprintf(PNG,"En proton th=%d",th2[konf]);
	E_E_hist->GetYaxis()->SetTitle(PNG);
	c1.cd(2);
	E_E_hist->DrawCopy("colz");
	//sprintf(PNG,"../wyniki/%d_%d_E_E_hist.png",th1[konf],th2[konf]);
	//c1.SaveAs(PNG);
	sprintf(PNG,"En proton th=%d",th1[konf]);
	E2_proj->GetXaxis()->SetTitle(PNG);
	c1.cd(3);
	E2_proj->DrawCopy("colz");
	//sprintf(PNG,"../wyniki/%d_%d_E2_proj.png",th1[konf],th2[konf]);
	//c1.SaveAs(PNG);
	sprintf(PNG,"En proton th=%d",th2[konf]);
	E3_proj->GetXaxis()->SetTitle(PNG);
	c1.cd(4);
	E3_proj->DrawCopy("colz");
	sprintf(PNG,"../wyniki/ppn_%d_%d.png",th1[konf],th2[konf]);
	c1.SaveAs(PNG);
	F->Close();
}

return 0;
}

