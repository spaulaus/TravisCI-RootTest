///@file RootInterface.cpp
///@brief Provides an interface to ROOT for scan programs
///@author K. Smith and S. V. Paulauskas
///@date May 21, 2017
#ifndef __ROOTINTERFACE_HPP__
#define __ROOTINTERFACE_HPP__

#include <map>

#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TFile.h"

//Singleton class that handles everybody's access to ROOT
class RootInterface {
public:
    ///@return only instance of XmlInterface class
    static RootInterface *get();

    ~RootInterface();

    TCanvas *GetCanvas() { return canvas_; }

    void IdleTask();

    void UpdateZoom(TVirtualPad *pad = gPad);

    void ResetZoom(TVirtualPad *pad = gPad);

    void OpenFile(const std::string &string) {
        TFile file(string.c_str(), "RECREATE");
        if(!file.IsOpen())
            throw std::invalid_argument("RootInterface::OpenFile - Couldn't open that stupid file!!!");

        TH1F h1("h1", "histo from a gaussian", 100, -3, 3);
        h1.FillRandom("gaus", 10000);
        h1.Write();
        file.Close();
    }

private:
    static RootInterface *instance_;
    RootInterface();
    void operator=(RootInterface const &); //!< copy constructor

    TCanvas *canvas_;

    static const int numAxes_ = 3;
    struct AxisInfo {
        double rangeUserMin[numAxes_];
        double rangeUserMax[numAxes_];
        double limitMin[numAxes_];
        double limitMax[numAxes_];
        bool reset;
    };

    std::map<TVirtualPad *, AxisInfo> zoomInfo_;
};

#endif //RootInterface_H
