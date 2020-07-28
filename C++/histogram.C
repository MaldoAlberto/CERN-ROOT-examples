void histogram(){
	Int_t n1 = 100; // number of elements

	Float_t arreglo[n1];
	string line;
	Int_t sizet = 0;

	ifstream myfile ("salida.txt"); // name of the file to read 
	  if (myfile.is_open())
	  {
	    while ( getline (myfile,line) )
	    {
		if(sizet < n1)
		      	arreglo[sizet] = stof(line);
		sizet++;
	    }
	    myfile.close();
	  }
	

	Int_t locmin = TMath::LocMin(n1,arreglo); // min position value
	Int_t locmax = TMath::LocMax(n1,arreglo); // max position value

	Double_t ancho = 0.9; //variable  to modify the width bars
	cout << ancho << endl;
		printf("min  %lf max %lf ",arreglo[locmin],arreglo[locmax]);

		Double_t nx = (arreglo[locmax]/arreglo[locmax] - arreglo[locmin]/arreglo[locmax])/ancho;


	min_range = -3
	max_range =3 
	
	TH1F *gaus2 = new TH1F ("gauss","Hadamard", nx, min_range,max_range);

		for (Int_t t = 0; t < n1; t++)
		{	
			//cout << arreglo[t] << endl;
			gaus2->Fill(arreglo[t]/arreglo[locmax]);

		}


    //-------agrega esto--------
    TCanvas* c = new TCanvas;
    c->cd(1);
    Double_t norm = gaus2->GetEntries();
    gaus2->Scale(1/norm);
    gaus2->SetBarWidth(0.85);
    gaus2->SetFillColor(30);

    gaus2->Draw("histbar");
    c->Print("histograma_result.png", "png");
    //-----fin-------
    
}
