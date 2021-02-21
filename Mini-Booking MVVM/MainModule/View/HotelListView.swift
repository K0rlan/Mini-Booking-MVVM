//
//  HotelListView.swift
//  Mini-Booking MVVM
//
//  Created by Korlan Omarova on 20.02.2021.
//

import UIKit

protocol HotelListViewProtocol{
    func goToDetails(hotelID: Int)
    func setErrorAlert(error: Error)
}

class HotelListView: UIView {
    
    lazy var tableView: UITableView = {
        let tableView = UITableView()
        tableView.delegate = self
        tableView.dataSource = self
        tableView.backgroundColor = Constants.mainColor
        tableView.showsVerticalScrollIndicator = false
        tableView.register(HotelTableViewCell.self, forCellReuseIdentifier: "hotels")
        return tableView
    }()
    
    let activityIndicator: UIActivityIndicatorView = {
        let activityIndicator = UIActivityIndicatorView(style: .large)
        activityIndicator.color = .gray
        activityIndicator.hidesWhenStopped = true
        return activityIndicator
    }()
    
    
    var hotelsData: HotelList = .initial{
        didSet{
            setNeedsLayout()
        }
    }
    
    var hotels = [HotelList.Data]()
    
     var delegate: HotelListViewProtocol!
    
    override init(frame: CGRect = .zero) {
        super .init(frame: frame)
        self.backgroundColor = .white
        tableView.reloadData()
        setupViews()
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func layoutSubviews() {
        super.layoutSubviews()
        switch hotelsData {
        case .initial:
            tableView.isHidden = true
            self.activityIndicator.isHidden = false
        case .loading:
            tableView.isHidden = true
            self.activityIndicator.isHidden = false
        case .success(let success):
            tableView.isHidden = false
            self.activityIndicator.isHidden = true
            hotels = success
            tableView.reloadData()
        case .failure(let error):
            tableView.isHidden = true
            self.activityIndicator.isHidden = true
            delegate.setErrorAlert(error: error)
        }
    }
    
  
    
    private func setupViews(){
        [tableView, activityIndicator].forEach {
            self.addSubview($0)
            $0.translatesAutoresizingMaskIntoConstraints = false
        }
        tableView.topAnchor.constraint(equalTo: self.topAnchor).isActive = true
        tableView.leadingAnchor.constraint(equalTo: self.leadingAnchor).isActive = true
        tableView.trailingAnchor.constraint(equalTo: self.trailingAnchor).isActive = true
        tableView.bottomAnchor.constraint(equalTo: self.bottomAnchor).isActive = true
        
        activityIndicator.centerXAnchor.constraint(equalTo: self.centerXAnchor).isActive = true
        activityIndicator.centerYAnchor.constraint(equalTo: self.centerYAnchor).isActive = true
    }
}


extension HotelListView: UITableViewDelegate, UITableViewDataSource{
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return hotels.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "hotels", for: indexPath) as!
            HotelTableViewCell
        if indexPath.row == 0{
            cell.backgroundColor = .white
            cell.layer.cornerRadius = 30
            cell.layer.maskedCorners = [.layerMinXMinYCorner, .layerMaxXMinYCorner]
        }else{
            cell.layer.cornerRadius = 0
        }
        let hotel = hotels[indexPath.row]
        cell.titleLabel.text = hotel.name
        cell.addressLabel.text = hotel.address
        cell.distanceLabel.text = String("Distance from the city center: \(hotel.distance)")
        cell.starsLabel.text = String(hotel.stars)
        let suitesAvailabilityArray = hotel.suites_availability.components(separatedBy: ":")
        cell.suitesAvailabilityLabel.text = String("Number of available rooms: \(suitesAvailabilityArray.count)")
        return cell
    
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        HotelImage.sharedInstance.image = UIImage()
        delegate?.goToDetails(hotelID: hotels[indexPath.row].id)
    }
    
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 180
    }
    
}
