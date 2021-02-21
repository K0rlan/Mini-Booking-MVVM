//
//  DetailsView.swift
//  Mini-Booking MVVM
//
//  Created by Korlan Omarova on 20.02.2021.
//

import UIKit
import YandexMapsMobile

protocol DetailsViewProtocol{
    func setErrorAlert(error: Error)
}

class DetailsView: UIView {
    
    lazy var hotelImage: UIImageView = {
        let imageView = UIImageView()
        imageView.contentMode = .scaleAspectFill
        imageView.clipsToBounds = true
        return imageView
    }()
    
    lazy var titleLabel: UILabel = {
        let label = UILabel()
        label.font = .boldSystemFont(ofSize: 20)
        label.numberOfLines = 0
        label.textColor = .black
        return label
    }()
    
    lazy var starImage: UIImageView = {
        let imageView = UIImageView()
        imageView.contentMode = .scaleAspectFit
        return imageView
    }()
    
    lazy var addressLabel: UILabel = {
        let label = UILabel()
        label.font = .boldSystemFont(ofSize: 16)
        label.textColor = Constants.orange
        label.numberOfLines = 0
        return label
    }()
    
    lazy var starsLabel: UILabel = {
        let label = UILabel()
        label.textColor = .black
        return label
    }()
    
    lazy var distanceLabel: UILabel = {
        let label = UILabel()
        label.textColor = .black
        label.numberOfLines = 0
        return label
    }()
    
    lazy var suitesAvailabilityLabel: UILabel = {
        let label = UILabel()
        label.numberOfLines = 0
        return label
    }()
    
    lazy var lonLabel: UILabel = {
        let label = UILabel()
        return label
    }()
    
    lazy var latLabel: UILabel = {
        let label = UILabel()
        return label
    }()
    
    let activityIndicator: UIActivityIndicatorView = {
        let activityIndicator = UIActivityIndicatorView(style: .large)
        activityIndicator.color = .gray
        activityIndicator.hidesWhenStopped = true
        return activityIndicator
    }()
    
    lazy var mapView: YMKMapView = {
        let view = YMKMapView()
        return view
    }()
   
    var hotelsData: HotelDescription = .initial{
        didSet{
            setNeedsLayout()
        }
    }
    
    var delegate: DetailsViewProtocol!
    
    override init(frame: CGRect = .zero) {
        super .init(frame: frame)
        self.backgroundColor = .white
        setupViews()
       
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func layoutSubviews() {
        super.layoutSubviews()
        switch hotelsData {
        case .initial:
            self.activityIndicator.isHidden = false
            self.mapView.isHidden = true
        case .loading:
            self.activityIndicator.isHidden = false
            self.mapView.isHidden = true
        case .success(let success):
            self.activityIndicator.isHidden = true
            self.mapView.isHidden = false
            self.update(viewData: success)
        case .failure(let error):
            self.activityIndicator.isHidden = true
            delegate?.setErrorAlert(error: error)
        }
    }
    
    private func setupMap(lat: Double, lon: Double){
        let location = YMKPoint(latitude: lat, longitude: lon)
        mapView.mapWindow.map.move(
                   with: YMKCameraPosition(target: location, zoom: 15, azimuth: 0, tilt: 0),
                   animationType: YMKAnimation(type: YMKAnimationType.smooth, duration: 5),
                   cameraCallback: nil)
        mapView.mapWindow.map.mapObjects.addPlacemark(with: location, image: Constants.marker!)
    }
    
    private func update(viewData: HotelDescription.Data?){
        guard let data = viewData  else { return }
        self.hotelImage.image = HotelImage.sharedInstance.image
        titleLabel.text = data.name
        addressLabel.text = data.address
        starsLabel.text = String(data.stars)
        starImage.image = Constants.starFilled
        distanceLabel.text = String("Distance from the city center: \(data.distance)")
        lonLabel.text = String(data.lon)
        latLabel.text = String(data.lat)
        suitesAvailabilityLabel.text = String("Available rooms: \(data.suites_availability)")
        if HotelImage.sharedInstance.image == UIImage(){
            self.hotelImage.image = Constants.noImage
        }
        setupMap(lat: data.lat, lon: data.lon)
    }
    
    private func setupViews(){
        [hotelImage, titleLabel, addressLabel, starsLabel, starImage, distanceLabel, activityIndicator, suitesAvailabilityLabel, mapView].forEach {
            self.addSubview($0)
            $0.translatesAutoresizingMaskIntoConstraints = false
        }
        
        hotelImage.heightAnchor.constraint(equalToConstant: 200).isActive = true
        hotelImage.topAnchor.constraint(equalTo: self.topAnchor).isActive = true
        hotelImage.leadingAnchor.constraint(equalTo: self.leadingAnchor).isActive = true
        hotelImage.trailingAnchor.constraint(equalTo: self.trailingAnchor).isActive = true
        
        titleLabel.topAnchor.constraint(equalTo: hotelImage.bottomAnchor, constant: 10).isActive = true
        titleLabel.leadingAnchor.constraint(equalTo: self.leadingAnchor, constant: 20).isActive = true
        titleLabel.trailingAnchor.constraint(equalTo: self.trailingAnchor, constant: -20).isActive = true
        
        starsLabel.topAnchor.constraint(equalTo: titleLabel.bottomAnchor, constant: 10).isActive = true
        starsLabel.leadingAnchor.constraint(equalTo: self.leadingAnchor, constant: 20).isActive = true
        
        starImage.topAnchor.constraint(equalTo: titleLabel.bottomAnchor, constant: 12).isActive = true
        starImage.leadingAnchor.constraint(equalTo: starsLabel.trailingAnchor, constant: 5).isActive = true
        starImage.widthAnchor.constraint(equalToConstant: 15).isActive = true
        starImage.heightAnchor.constraint(equalToConstant: 15).isActive = true
        
        addressLabel.topAnchor.constraint(equalTo: starImage.bottomAnchor, constant: 10).isActive = true
        addressLabel.leadingAnchor.constraint(equalTo: self.leadingAnchor, constant: 20).isActive = true
        addressLabel.trailingAnchor.constraint(equalTo: self.trailingAnchor, constant: -20).isActive = true
        
        distanceLabel.topAnchor.constraint(equalTo: addressLabel.bottomAnchor, constant: 10).isActive = true
        distanceLabel.centerXAnchor.constraint(equalTo: self.centerXAnchor).isActive = true
        distanceLabel.leadingAnchor.constraint(equalTo: self.leadingAnchor, constant: 20).isActive = true
        distanceLabel.trailingAnchor.constraint(equalTo: self.trailingAnchor, constant: -20).isActive = true
        
        suitesAvailabilityLabel.topAnchor.constraint(equalTo: distanceLabel.bottomAnchor, constant: 10).isActive = true
        suitesAvailabilityLabel.leadingAnchor.constraint(equalTo: self.leadingAnchor, constant: 20).isActive = true
        suitesAvailabilityLabel.trailingAnchor.constraint(equalTo: self.trailingAnchor, constant: -20).isActive = true
        
        mapView.topAnchor.constraint(equalTo: suitesAvailabilityLabel.bottomAnchor, constant: 10).isActive = true
        mapView.leadingAnchor.constraint(equalTo: self.leadingAnchor).isActive = true
        mapView.trailingAnchor.constraint(equalTo: self.trailingAnchor).isActive = true
        mapView.bottomAnchor.constraint(equalTo: self.bottomAnchor).isActive = true
        
        activityIndicator.centerYAnchor.constraint(equalTo: self.centerYAnchor).isActive = true
        activityIndicator.centerXAnchor.constraint(equalTo: self.centerXAnchor).isActive = true
        
    }
    
}
