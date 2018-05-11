{
//=========Macro generated from canvas: c1/c1
//=========  (Wed May  9 02:38:11 2018) by ROOT version5.34/36
   TCanvas *c1 = new TCanvas("c1", "c1",10,108,700,500);
   c1->Range(-0.275,-110313.7,2.475,992822.9);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *htemp = new TH1F("htemp","col3 {col1==2}",100,0,2.2);
   htemp->SetBinContent(1,102009);
   htemp->SetBinContent(46,840485);
   htemp->SetBinContent(91,4306);
   htemp->SetEntries(946800);
   htemp->SetDirectory(0);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("htemp");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 946800 ");
   text = ptstats->AddText("Mean  = 0.8968");
   text = ptstats->AddText("RMS   = 0.3188");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   htemp->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(htemp);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   htemp->SetLineColor(ci);
   htemp->GetXaxis()->SetTitle("col3");
   htemp->GetXaxis()->SetRange(1,100);
   htemp->GetXaxis()->SetLabelFont(42);
   htemp->GetXaxis()->SetLabelSize(0.035);
   htemp->GetXaxis()->SetTitleSize(0.035);
   htemp->GetXaxis()->SetTitleFont(42);
   htemp->GetYaxis()->SetLabelFont(42);
   htemp->GetYaxis()->SetLabelSize(0.035);
   htemp->GetYaxis()->SetTitleSize(0.035);
   htemp->GetYaxis()->SetTitleFont(42);
   htemp->GetZaxis()->SetLabelFont(42);
   htemp->GetZaxis()->SetLabelSize(0.035);
   htemp->GetZaxis()->SetTitleSize(0.035);
   htemp->GetZaxis()->SetTitleFont(42);
   htemp->Draw("colz");
   
   TPaveText *pt = new TPaveText(0.3739542,0.9370168,0.6260458,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("col3 {col1==2}");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
