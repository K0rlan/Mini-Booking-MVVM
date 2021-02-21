//
//  MainViewController.swift
//  Mini-Booking MVVM
//
//  Created by Korlan Omarova on 20.02.2021.
//

import UIKit

class MainViewController: UIViewController {
    
    lazy var navLabel: UILabel = {
        let label = UILabel()
        label.textColor = UIColor.white
        label.text = "Mini-Booking"
        label.font = .boldSystemFont(ofSize: 18)
        label.textColor = Constants.white
        return label
    }()
    
    lazy var filterByLocation: UIButton = {
        let button = UIButton()
        button.setImage(Constants.location, for: .normal)
        button.addTarget(self, action: #selector(filterByLocationPressed), for: .touchUpInside)
        return button
    }()
    
    lazy var separatorViewForNavBar: UIView = {
        let view = UIView()
        return view
    }()
    
    lazy var filterByRooms: UIButton = {
        let button = UIButton()
        button.setImage(Constants.bed, for: .normal)
        button.addTarget(self, action: #selector(filterByRoomsPressed), for: .touchUpInside)
        return button
    }()
    
    var hotelListView = HotelListView()
    
    private var viewModel = MainViewModel()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = .white
        hotelListView.delegate = self
        setNavigationBar()
        viewModel.startFetch()
        setupViews()
        updateView()
    }
    private func setNavigationBar(){
        navigationController?.navigationBar.barTintColor = Constants.mainColorForNav
        navigationItem.rightBarButtonItems = [UIBarButtonItem(customView: separatorViewForNavBar), UIBarButtonItem(customView: filterByRooms), UIBarButtonItem(customView: separatorViewForNavBar),UIBarButtonItem(customView: filterByLocation)]
        self.navigationItem.leftBarButtonItem = UIBarButtonItem.init(customView: navLabel)
    }
    
    private func updateView(){
        viewModel.updateViewData = { [weak self] hotelsData in
            self?.hotelListView.hotelsData = hotelsData
        }
    }
    
    @objc func filterByLocationPressed(){
        viewModel.filterByLocation()
    }
    
    @objc func filterByRoomsPressed(){
        viewModel.filterByRooms()
    }
  
    private func setupViews(){
        [hotelListView, separatorViewForNavBar].forEach {
            self.view.addSubview($0)
            $0.translatesAutoresizingMaskIntoConstraints = false
        }
        
        hotelListView.topAnchor.constraint(equalTo: self.view.safeAreaLayoutGuide.topAnchor).isActive = true
        hotelListView.leadingAnchor.constraint(equalTo: self.view.leadingAnchor).isActive = true
        hotelListView.trailingAnchor.constraint(equalTo: self.view.trailingAnchor).isActive = true
        hotelListView.bottomAnchor.constraint(equalTo: self.view.safeAreaLayoutGuide.bottomAnchor).isActive = true
        
        filterByLocation.widthAnchor.constraint(equalToConstant: 33).isActive = true
        filterByLocation.heightAnchor.constraint(equalToConstant: 30).isActive = true
        
        filterByRooms.widthAnchor.constraint(equalToConstant: 33).isActive = true
        filterByRooms.heightAnchor.constraint(equalToConstant: 30).isActive = true
        
        separatorViewForNavBar.widthAnchor.constraint(equalToConstant: 7).isActive = true
        separatorViewForNavBar.heightAnchor.constraint(equalToConstant: 7).isActive = true
        
    }

}

extension MainViewController: HotelListViewProtocol{
    func goToDetails(hotelID: Int) {
        let detailsViewController = DetailsViewController()
        detailsViewController.getHotelID(hotelID: hotelID)
        self.navigationController?.pushViewController(detailsViewController, animated: true)
    }
    func setErrorAlert(error: Error) {
        let alertViewController = UIAlertController(title: "Error", message: error.localizedDescription, preferredStyle: .alert)
        alertViewController.addAction(UIAlertAction(title: "Ok", style: .default, handler: nil))
        present(alertViewController, animated: true, completion: nil)
        
    }
}
