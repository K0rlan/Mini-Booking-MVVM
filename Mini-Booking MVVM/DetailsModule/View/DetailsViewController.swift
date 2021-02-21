//
//  DetailsViewController.swift
//  Mini-Booking MVVM
//
//  Created by Korlan Omarova on 20.02.2021.
//

import UIKit

class DetailsViewController: UIViewController {
    
    private var viewModel = DetailsViewModel()
    var detailsView = DetailsView()
    
    var mainVC = MainViewController()
        
    override func viewDidLoad() {
        super.viewDidLoad()
        setupViews()
        detailsView.delegate = self
        self.view.backgroundColor = .white
        self.navigationController?.navigationBar.tintColor = .white
        updateView()
    }
    
    public func getHotelID(hotelID: Int){
        viewModel.startFetch(hotelID: hotelID)
    }
    
    func updateView(){
        viewModel.updateViewData = { [weak self] viewData in
            self?.detailsView.hotelsData = viewData
        }
    }
    
    func updateImage(){
        viewModel.updateViewData = { [weak self] viewData in
            self?.detailsView.hotelsData = viewData
        }
    }
    
    private func setupViews(){
        self.view.addSubview(detailsView)
        detailsView.translatesAutoresizingMaskIntoConstraints = false
        
        detailsView.topAnchor.constraint(equalTo: self.view.safeAreaLayoutGuide.topAnchor).isActive = true
        detailsView.leadingAnchor.constraint(equalTo: self.view.leadingAnchor).isActive = true
        detailsView.trailingAnchor.constraint(equalTo: self.view.trailingAnchor).isActive = true
        detailsView.bottomAnchor.constraint(equalTo: self.view.safeAreaLayoutGuide.bottomAnchor).isActive = true
    }
}

extension DetailsViewController: DetailsViewProtocol{
    func setErrorAlert(error: Error) {
        let alertViewController = UIAlertController(title: "Error", message: error.localizedDescription, preferredStyle: .alert)
        alertViewController.addAction(UIAlertAction(title: "Ok", style: .default, handler: nil))
        present(alertViewController, animated: true, completion: nil)        
    }
}
