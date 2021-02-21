//
//  HotelTableViewCell.swift
//  Mini-Booking MVVM
//
//  Created by Korlan Omarova on 20.02.2021.
//

import UIKit

class HotelTableViewCell: UITableViewCell {
    
    lazy var titleLabel: UILabel = {
        let label = UILabel()
        label.font = .boldSystemFont(ofSize: 20)
        label.numberOfLines = 0
        label.textColor = .black
        return label
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
        label.textColor = Constants.mainColor
        label.font = .boldSystemFont(ofSize: 18)
        return label
    }()
    
    lazy var starImage: UIImageView = {
        let imageView = UIImageView()
        imageView.contentMode = .scaleAspectFit
        imageView.image = Constants.starFilled
        return imageView
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

    
    override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
        selectionStyle = .none
        setupViews()
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    private func setupViews(){
        [titleLabel, addressLabel, starsLabel, starImage, distanceLabel, suitesAvailabilityLabel].forEach {
            self.addSubview($0)
            $0.translatesAutoresizingMaskIntoConstraints = false
        }
        
        
        titleLabel.topAnchor.constraint(equalTo: self.topAnchor, constant: 10).isActive = true
        titleLabel.leadingAnchor.constraint(equalTo: self.leadingAnchor, constant: 30).isActive = true
        titleLabel.trailingAnchor.constraint(equalTo: self.trailingAnchor, constant: -30).isActive = true
        
        starImage.topAnchor.constraint(equalTo: titleLabel.bottomAnchor, constant: 10).isActive = true
        starImage.leadingAnchor.constraint(equalTo: starsLabel.trailingAnchor, constant: 5).isActive = true
        starImage.widthAnchor.constraint(equalToConstant: 15).isActive = true
        starImage.heightAnchor.constraint(equalToConstant: 15).isActive = true

        starsLabel.topAnchor.constraint(equalTo: titleLabel.bottomAnchor, constant: 8).isActive = true
        starsLabel.leadingAnchor.constraint(equalTo: self.leadingAnchor, constant: 30).isActive = true
        
        addressLabel.topAnchor.constraint(equalTo: starImage.bottomAnchor, constant: 5).isActive = true
        addressLabel.leadingAnchor.constraint(equalTo: self.leadingAnchor, constant: 30).isActive = true
        addressLabel.trailingAnchor.constraint(equalTo: self.trailingAnchor, constant: -30).isActive = true
               
        distanceLabel.topAnchor.constraint(equalTo: addressLabel.bottomAnchor, constant: 5).isActive = true
        distanceLabel.leadingAnchor.constraint(equalTo: self.leadingAnchor, constant: 30).isActive = true
        distanceLabel.trailingAnchor.constraint(equalTo: self.trailingAnchor, constant: -30).isActive = true
               
        suitesAvailabilityLabel.topAnchor.constraint(equalTo: distanceLabel.bottomAnchor, constant: 5).isActive = true
        suitesAvailabilityLabel.leadingAnchor.constraint(equalTo: self.leadingAnchor, constant: 30).isActive = true
        suitesAvailabilityLabel.trailingAnchor.constraint(equalTo: self.trailingAnchor, constant: -30).isActive = true
        suitesAvailabilityLabel.bottomAnchor.constraint(equalTo: self.bottomAnchor, constant: -10).isActive = true
        
               
    }
}

