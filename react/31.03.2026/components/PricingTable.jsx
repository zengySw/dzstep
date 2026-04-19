import React from 'react';
import PricingCard from './PricingCard';

const plans = [
  {
    title: 'Basic',
    price: '2.99',
    color: '#0d9488',
    features: [
      { text: '1 project', included: true },
      { text: 'Email support', included: true },
      { text: 'Priority support', included: false },
      { text: 'Advanced analytics', included: false }
    ]
  },
  {
    title: 'Standard',
    price: '5.99',
    color: '#2563eb',
    isFeatured: true,
    features: [
      { text: '5 projects', included: true },
      { text: 'Email support', included: true },
      { text: 'Priority support', included: true },
      { text: 'Advanced analytics', included: false }
    ]
  },
  {
    title: 'Premium',
    price: '11.99',
    color: '#7c3aed',
    features: [
      { text: 'Unlimited projects', included: true },
      { text: '24/7 support', included: true },
      { text: 'Priority support', included: true },
      { text: 'Advanced analytics', included: true }
    ]
  }
];

const PricingTable = ({ isDark }) => {
  return (
    <section className="pricing-table" aria-label="Pricing card preview">
      {plans.map((plan) => (
        <PricingCard key={plan.title} {...plan} isDark={isDark} />
      ))}
    </section>
  );
};

export default PricingTable;
